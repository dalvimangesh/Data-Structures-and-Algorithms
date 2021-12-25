#include <stdio.h>

//function to print possible way's to complete the 'tower of honai' game
void tower_of_honai(int source, int target, int intermediate, int disks)
{
    //no disk at source
    if (disks < 0)
        return;

    //if one disk present then directly transfering it from source to target (base condition)
    if (disks == 1)
    {
        printf("Move Disk %d from Pole %d to Pole %d\n", disks, source, target);
        return;
    }

    // transfering disk from source to intermediate
    tower_of_honai(source, intermediate, target, disks - 1);

    //printing way
    printf("Move Disk %d from Pole %d to Pole %d\n", disks, source, target);

    //transfering disk from intermediate to target
    tower_of_honai(intermediate, target, source, disks - 1);
}

int main()
{
    //space for number of disks
    int n;
    scanf("\n %d", &n);

    //initially source is tower 0 and target is tower 2
    tower_of_honai(0, 2, 1, n);

    return 0;
}