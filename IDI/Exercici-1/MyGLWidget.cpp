//#include <GL/glew.h>
#include "MyGLWidget.h"

#include <iostream>

MyGLWidget::MyGLWidget (QWidget* parent) : QOpenGLWidget(parent), program(NULL) {
    setFocusPolicy(Qt::StrongFocus);  // per rebre events de teclat
}

MyGLWidget::~MyGLWidget () {
    if (program != NULL) delete program;
}

void MyGLWidget::initializeGL () {
    // Cal inicialitzar l'ús de les funcions d'OpenGL
    initializeOpenGLFunctions();

    glClearColor (0.5, 0.7, 1.0, 1.0); // defineix color de fons (d'esborrat)
    carregaShaders();
    creaBuffers();
}

void MyGLWidget::paintGL () {
    // En cas de voler canviar els paràmetres del viewport, descomenteu la crida següent i
    // useu els paràmetres que considereu (els que hi ha són els de per defecte)

    //glViewport (0, 0, ample, alt);
  
    glClear (GL_COLOR_BUFFER_BIT);  // Esborrem el frame-buffer

    pintaSector();
    pintaCistella();
    pintaBase();

    // Desactivem el VAO
    glBindVertexArray(0);
}

void MyGLWidget::pintaSector(){
    for (float angleCurrent = 0.0f; angleCurrent < 360.0f; angleCurrent += angleSectorNoria) {
        modelTransformSector(glm::radians(angleCurrent));
        glBindVertexArray(VAO_Sector);
        glDrawArrays(GL_TRIANGLES, 0, 21);
    }
}

void MyGLWidget::pintaBase(){
    modelTransformBase();
    glBindVertexArray(VAO_Base);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void MyGLWidget::pintaCistella(){
    int cistellesAPintar = 1;
    if (londonEyeComplete) cistellesAPintar = 8;
    
    float angleCurrent = 0.0f;
    for (int i = 0; i < cistellesAPintar; i++) {
        modelTransformCistella(angleCurrent);
        glBindVertexArray(VAO_Cistella);
        glDrawArrays(GL_TRIANGLES, 0, 18);

        angleCurrent += 45.0f;
    }
}

void MyGLWidget::modelTransformCistella(float angleOffset){

    glm::mat4 TG (1.0f);

    // 5: el centro de los sectores no es el (0,0), sino (0, -0.25), y por lo tanto hace falta esta última traslación
    // *Del buffer de la cesta se sabe que la mitad de su altura es 0.7*
    // *despues del escalado, esta altura es entonces (0.7*(1/10))*
    TG = glm::translate(TG, glm::vec3(0.0f, -0.25f - 0.7f*(1.0f/10.0f), 0.0f));
    // 4: con la traslación anterior, esta rotación desplazara la cesta por la circumferencia de los sectores
    TG = glm::rotate(TG, glm::radians(rotation+angleOffset), glm::vec3(0.0f, 0.0f, -1.0f));
    // 3: trasladamos por la longitud del sector
    TG = glm::translate(TG, glm::vec3(0.5f, 0.0f, 0.0f));
    // 2: hacemos la escala por el factor que se pide
    TG = glm::scale(TG, glm::vec3(1.0f/10.0f));
    // 1: aplicamos una rotación inversa para que la cesta quede recta despues de la rotación de la interacción
    TG = glm::rotate(TG, glm::radians(-rotation-angleOffset), glm::vec3(0.0f, 0.0f, -1.0f));

    glUniformMatrix4fv(TGLoc, 1, GL_FALSE, &TG[0][0]);
    glUniform1i(es_baseLoc, false);  // es base? no => uniform es false
}

void MyGLWidget::modelTransformBase(){
    glm::mat4 TG (1.0f);

    // 3: trasladamos tal que los vertices inferiores esten en el y = -1
    TG = glm::translate(TG, glm::vec3(0.0f, -1.0f, 0.0f));
    // 2: hacemos la escala tal que el modelo tenga altura de 0.75
    TG = glm::scale(TG, glm::vec3(1.0f, 0.75f/2.0f, 1.0f));                                                       
    // 1: trasladamos tal que los vertices inferiores esten en y = 0
    TG = glm::translate(TG, glm::vec3(0.0f, 1.0f, 0.0f));
                                                                
    glUniformMatrix4fv(TGLoc, 1, GL_FALSE, &TG[0][0]);
    glUniform1i(es_baseLoc, true); // es base? sí => uniform es true
}

void MyGLWidget::modelTransformSector(float angleRadians){
    glm::mat4 TG (1.0f);

    // 3: movemos el modelo tal que el centro de la sinia acabe sobre el vertice superior de la base
    TG = glm::translate(TG, glm::vec3(0.0f, -0.25f, 0.0f));
    // 2: escalamos el modelo por 0.5
    TG = glm::scale(TG, glm::vec3(0.5f));
    // 1: rotamos el modelo respecto Z por el angulo del parametro + angulo adicional de la interacción
    TG = glm::rotate(TG, angleRadians + glm::radians(rotation), glm::vec3(0.0f, 0.0f, -1.0f));

    glUniformMatrix4fv(TGLoc, 1, GL_FALSE, &TG[0][0]);
    glUniform1i(es_baseLoc, false);  // es base? no => uniform es false
}

void MyGLWidget::resizeGL (int w, int h) {
// Aquest codi és necessari únicament per a MACs amb pantalla retina.
#ifdef __APPLE__
  GLint vp[4];
  glGetIntegerv (GL_VIEWPORT, vp);
  ample = vp[2];
  alt = vp[3];
#else
  ample = w;
  alt = h;
#endif
}

void MyGLWidget::keyPressEvent(QKeyEvent* event) {
    makeCurrent();
    switch (event->key()) {

        case Qt::Key_Left: {
            rotation -= 5;
            break;
        }
        case Qt::Key_Right: {
            rotation += 5;
            break;
        }
        case Qt::Key_8: {
            londonEyeComplete = true;
            break;
        }
        case Qt::Key_1: {
            londonEyeComplete = false;
            break;
        }
        default: event->ignore(); break;
    }
    update();
}

void MyGLWidget::creaBuffers (){
    creaBufferSector();
    creaBufferBase();
    creaBufferCistella();
}

void MyGLWidget::creaBufferBase(){
    glm::vec3 Colors[3];
    glm::vec3 Vertices[3];
    int i=0,c=0;
    Vertices[i++] = glm::vec3(0.0f , 1.0f, 0.0f);
    Vertices[i++] = glm::vec3(-0.15, -1.0f, 0.0f);
    Vertices[i++] = glm::vec3(0.15, -1.0f, 0.0f);
    Colors[c++]=COLOR_GROC;
    Colors[c++]=COLOR_GROC;
    Colors[c++]=COLOR_GROC;

    // Creació del Vertex Array Object (VAO) que usarem per pintar
    glGenVertexArrays(1, &VAO_Base);
    glBindVertexArray(VAO_Base);

    // Creació del buffer amb les dades dels vèrtexs
    GLuint VBO[2];
    glGenBuffers(2, VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);
    // Activem l'atribut que farem servir per vèrtex (només el 0 en aquest cas)
    glVertexAttribPointer(vertexLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(vertexLoc);

    // Creació del buffer de colors
    glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Colors), Colors, GL_STATIC_DRAW);
    glVertexAttribPointer(colorLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(colorLoc);

    // Desactivem el VAO
    glBindVertexArray(0);
}

void MyGLWidget::creaBufferSector() {
    glm::vec3 Colors[21];
    glm::vec3 Vertices[21];
    int i=0,c=0;
    float alfa=glm::radians(angleSectorNoria);
    float r[]={0.4f, 0.7f,  1.0f};
    float gruix=0.05f;
    Vertices[i++] = glm::vec3(0.0f , 0.0f, 0.0f);
    Vertices[i++] = glm::vec3(1.0f, 0.0f, 0.0f);
    Vertices[i++] = glm::vec3((r[2]-gruix)*cos(alfa/6), (r[2]-gruix)*sin(alfa/6), 0.0f);
    Colors[c++]=COLOR_BLAU;
    Colors[c++]=COLOR_BLAU;
    Colors[c++]=COLOR_BLAU;

    for(int k=0;k<3;k++){
        Vertices[i++] = glm::vec3(r[k]*cos(alfa), r[k]*sin(alfa), 0.0);
        Vertices[i++] = glm::vec3((r[k]-gruix)*cos(alfa), (r[k]-gruix)*sin(alfa), 0.0);
        Vertices[i++] = glm::vec3(r[k]-gruix, 0, 0.0);

        Vertices[i++] = glm::vec3(r[k]*cos(alfa), r[k]*sin(alfa), 0.0);
        Vertices[i++] = glm::vec3(r[k]-gruix, 0, 0.0);
        Vertices[i++] = glm::vec3(r[k], 0, 0.0);

        for(int n=0;n<6;n++){    
            if(k==0){
                Colors[c++]=COLOR_VERMELL;
            } else if (k==1) {
                Colors[c++]=COLOR_GROC;
            } else {
                Colors[c++]=COLOR_BLAU;
            }
        }
    }

    // Creació del Vertex Array Object (VAO) que usarem per pintar
    glGenVertexArrays(1, &VAO_Sector);
    glBindVertexArray(VAO_Sector);

    // Creació del buffer amb les dades dels vèrtexs
    GLuint VBO[2];
    glGenBuffers(2, VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);
    // Activem l'atribut que farem servir per vèrtex (només el 0 en aquest cas)
    glVertexAttribPointer(vertexLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(vertexLoc);

    // Creació del buffer de colors
    glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Colors), Colors, GL_STATIC_DRAW);
    glVertexAttribPointer(colorLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(colorLoc);

    // Desactivem el VAO
    glBindVertexArray(0);
}

void MyGLWidget::creaBufferCistella() {
    float w = 0.6;
    float h = 0.7;

    glm::vec3 Colors[18];
    glm::vec3 Vertices[18];
    int i=0;

    Colors[i]=COLOR_BLAU_FLUIX; Vertices[i++] = glm::vec3(-1, 0.0, 0.0);
    Colors[i]=COLOR_BLAU_FLUIX; Vertices[i++] = glm::vec3(-w,  h, 0.0);
    Colors[i]=COLOR_BLAU_FLUIX; Vertices[i++] = glm::vec3(-w, -h, 0.0);

    Colors[i]=COLOR_BLAU_FLUIX; Vertices[i++] = glm::vec3(-w,  h , 0.0);
    Colors[i]=COLOR_BLAU_FLUIX; Vertices[i++] = glm::vec3(-w, -h, 0.0);
    Colors[i]=COLOR_BLAU_FLUIX; Vertices[i++] = glm::vec3( w,  h, 0.0);

    Colors[i]=COLOR_BLAU_FLUIX; Vertices[i++] = glm::vec3( w,  h, 0.0);
    Colors[i]=COLOR_BLAU_FLUIX; Vertices[i++] = glm::vec3(-w, -h, 0.0);
    Colors[i]=COLOR_BLAU_FLUIX; Vertices[i++] = glm::vec3( w, -h, 0.0);

    Colors[i]=COLOR_BLAU_FLUIX; Vertices[i++] = glm::vec3( w, -h, 0.0);
    Colors[i]=COLOR_BLAU_FLUIX; Vertices[i++] = glm::vec3( w,  h, 0.0);
    Colors[i]=COLOR_BLAU_FLUIX; Vertices[i++] = glm::vec3( 1, 0.0, 0.0);

    Colors[i]=COLOR_BLANC; Vertices[i++] = glm::vec3(-w*0.8,  h*0.8 , 0.0);
    Colors[i]=COLOR_BLANC; Vertices[i++] = glm::vec3(-w*0.8, 0, 0.0);
    Colors[i]=COLOR_BLANC; Vertices[i++] = glm::vec3( w*0.8,  h*0.8, 0.0);

    Colors[i]=COLOR_BLANC; Vertices[i++] = glm::vec3( w*0.8,  h*0.8, 0.0); 
    Colors[i]=COLOR_BLANC; Vertices[i++] = glm::vec3(-w*0.8, 0, 0.0);
    Colors[i]=COLOR_BLANC; Vertices[i++] = glm::vec3( w*0.8, 0, 0.0);


    // Creació del Vertex Array Object (VAO) que usarem per pintar
    glGenVertexArrays(1, &VAO_Cistella);
    glBindVertexArray(VAO_Cistella);

    // Creació del buffer amb les dades dels vèrtexs
    GLuint VBO[2];
    glGenBuffers(2, VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);
    // Activem l'atribut que farem servir per vèrtex (només el 0 en aquest cas)
    glVertexAttribPointer(vertexLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(vertexLoc);

    // Creació del buffer de colors
    glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Colors), Colors, GL_STATIC_DRAW);
    glVertexAttribPointer(colorLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(colorLoc);

    // Desactivem el VAO
    glBindVertexArray(0);
}

void MyGLWidget::carregaShaders()
{
    // Creem els shaders per al fragment shader i el vertex shader
    QOpenGLShader fs (QOpenGLShader::Fragment, this);
    QOpenGLShader vs (QOpenGLShader::Vertex, this);

    // Carreguem el codi dels fitxers i els compilem
    fs.compileSourceFile("shaders/basicShader.frag");
    vs.compileSourceFile("shaders/basicShader.vert");
    
    // Creem el program
    program = new QOpenGLShaderProgram(this);
    // Li afegim els shaders corresponents
    program->addShader(&fs);
    program->addShader(&vs);
    // Linkem el program
    program->link();
    // Indiquem que aquest és el program que volem usar
    program->bind();

    // Obtenim identificador per a l'atribut “vertex” del vertex shader
    vertexLoc = glGetAttribLocation (program->programId(), "vertex");
    colorLoc =  glGetAttribLocation (program->programId(), "color");

    // uniforms
    TGLoc =  glGetUniformLocation(program->programId(), "TG");
    es_baseLoc = glGetUniformLocation(program->programId(), "es_base");
}
