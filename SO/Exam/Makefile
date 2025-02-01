all: proc_time nproc_time nproc_time_max max_5sec

nproc_time: nproc_time.c
	gcc nproc_time.c -o nproc_time

nproc_time_max: nproc_time_max.c
	gcc nproc_time_max.c -o nproc_time_max

proc_time: proc_time.c
	gcc proc_time.c -o proc_time

max_5sec: max_5sec.c
	gcc max_5sec.c -o max_5sec

clean:
	rm proc_time nproc_time nproc_time_max max_5sec pipe