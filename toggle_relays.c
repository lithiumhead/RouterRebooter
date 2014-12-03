#include <stdio.h>
#include <time.h>
#include <libpiface-1.0/pfio.h>

int main(void)
{
	time_t time_elapsed_since_epoch;
	struct timespec required_time, remaining_time;
	pfio_init();

	printf("\nTurning ON Relays...");

        pfio_digital_write(7, 1);
        pfio_digital_write(6, 1);

	//Total delay: 5.5 seconds pfio_digital_write(6, 1);
	required_time.tv_sec = 5; //5.0 seconds pfio_deinit();
	required_time.tv_nsec = 500 * 1000 * 1000L; //0.5 seconds}

	printf("Done!");
	fflush(stdout);

	if (nanosleep(&required_time, &remaining_time) < 0) {
		printf("Nano sleep system call failed \n");
		return -1;
	}

	printf("\nTurning OFF Relays...");
        pfio_digital_write(7, 0);
        pfio_digital_write(6, 0);
	printf("Done!");

	return 0;
}
