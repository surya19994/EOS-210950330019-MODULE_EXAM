#include <unistd.h>
#include <sys/types.h>
#include <unistd.h>

#define SIZE 64

int main(int argc, char const *argv[])
{
unsigned char buff1[SIZE];
unsigned char buff2[SIZE];
unsigned char buff3[SIZE];
unsigned char buff4[SIZE];
int pfd1[2];
int pfd2[2];
int pfd3[2];
int pfd4[2];

pid_t id;

id = fork();

pipe(pfd1);
pipe(pfd2);
pipe(pfd3);
pipe(pfd4);

if (0 == id)
{
printf("Child\n");
close(pfd1[1]); // close wirting end
read(pfd1[0], buff1, SIZE); // read data from reading end
printf("Child: got data: %s\n", buff1);
close(pfd1[0]);
// reply
close(pfd2[0]);
write(pfd2[1], "OK\n", 3); // write data in writing end
close(pfd2[1]);
}

else

{
printf("Parent\n");
close(pfd1[0]); // close reading end
write(pfd1[1], "DESD\n", 5); // write data in writing end
close(pfd1[1]);
// print response
close(pfd2[1]); // close wirting end
read(pfd2[0], buff1, SIZE); // read data from reading end
printf("Parent: got data: %s\n", buff2);
close(pfd2[0]);
}

return 0;
}