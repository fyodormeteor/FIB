/*  Draw images on a board (in character mode)
    2023-24 Q1

    https://github.com/fyodormeteor
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Image
{
    string name;
    int depth;
    int i, j;
    vector<string> v;
};

typedef vector<Image> ListImages;

// Pre: The input has a description of an image with this format:
//      - First line: name depth i j n m
//      - n lines with m characters each (the contents of v)
//        These characters are different from whitespace, as we use '.' to represent empty character.
Image readImage()
{
    Image image;
    string name;
    int depth, i, j, n, m;
    cin >> name >> depth >> i >> j >> n >> m;

    vector<string> v(n);
    for (int x = 0; x < n; x++)
        cin >> v[x];

    image.name = name;
    image.depth = depth;
    image.i = i;
    image.j = j;
    image.v = v;

    return image;
}

// Pre: listimages contains a non-empty list of valid images.
// Post: N,M are the dimensions of the minimum board such that
//       all of those images fit in it.
//       In other words, N,M must be the minimum naturals satisfying that,
//       for each image in listimages,
//       if i,j are its location and n,m are the dimensions of its v,
//       then i+n<=N and j+m<=M must be satisfied,
void computeMinimumBoardDimensions(const ListImages &listimages, int &N, int &M)
{
    N = M = 0;
    int size = listimages.size();

    for(int i = 0; i < size; ++i)
    {
        int n = listimages[i].v.size();
        int m = listimages[i].v[0].size();

        int min_N = listimages[i].i + n;
        int min_M = listimages[i].j + m;

        if (N < min_N) N = min_N;
        if (M < min_M) M = min_M;
    }
}

// Pre:  image is valid and board is valid and image fits in board.
// Post: image has been drawn on board. Nothing else has changed.
//       Recall that occurrences of character '.' in image are not printed on board!
void drawImage(const Image &image, vector<string> &board)
{
    int n = image.v.size();
    int m = image.v[0].size();

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            char c = image.v[i][j];
            if (c != '.') board[image.i + i][image.j + j] = c;
        }
    }
}

// Pre:  image1, image2 represent valid images.
// Post: Returns true iff one of the following conditions holds:
//         - depth of image1 is strictly bigger than depth of image2.
//         - image1 and image2 have same depth, but image1 has smaller name than image2.
bool compareImages(Image image1, Image image2)
{
    if (image1.depth == image2.depth)
    {
        if (image1.name < image2.name) return true;
        return false;
    }
    return (image1.depth > image2.depth);
}

// Pre: listimages has a list of valid images.
// Post: prints on the output the result of drawing all of those
//       images on the minimum board such that all of them fit in,
//       and sorted by depth and name.
void drawListImages(ListImages &listimages)
{
    sort(listimages.begin(), listimages.end(), compareImages);

    int N, M;
    computeMinimumBoardDimensions(listimages, N, M);
    vector<string> board(N, string(M, '.'));

    for (int i = 0; i < int(listimages.size()); i++)
        drawImage(listimages[i], board);

    for (int i = 0; i < N; i++)
        cout << board[i] << endl;

    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    ListImages listimages(n);
    for (int i = 0; i < n; i++)
        listimages[i] = readImage();

    drawListImages(listimages);
}