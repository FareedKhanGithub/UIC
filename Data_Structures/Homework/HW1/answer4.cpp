
int count = 10, *temp, sum = 0;

temp = &count;  //&takes the address count ands puts it in temp


*temp = 20;   //*goes to temp but since temp value is address 2 it is then sent to count
                 //which then changes 10 to 20

temp = &sum;  // & grabs address of sum makes it equal to temp value and changes
                //address 2 to address 3



*temp = count;       //*temp point now equals the value in 20. Since temp value equal
                   //Address sums value of 0 changes to counts 20.
                    

printf("count = %d, *temp = %d, sum = %d\n", count, *temp, sum);   //this is the C way
                                                                  //printing things
 //if you were to compile and run this properly it would print out

//count = 20, *temp=20, sum = 20/n, 20, 20, 20
