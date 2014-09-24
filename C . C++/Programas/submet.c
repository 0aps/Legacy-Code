//                                  ---PROTOTYPES---  start
int input (char *, int); //function for getting input from the user

void parseOctet (char *, int, char *, char *, char *, char *, char *); //function for parsing the...
//address the user entered into each octet and the mask.

char determineClass (int); // determines the class of the the ip address

int deterMask (int); // used for determining the subnet mask

int deterSubBroad (int, int); //used for determining the subnet broadcast address
//                                  ---PROTOTYPES---  end


#include <stdio.h> // include standard io functions
#include <stdlib.h> // include standard library functions

void main (void)  //main function of the program.  where the program starts
{
//                                  ---VARIABLE DECLARATIONS---  start
char classType;                  //a character representation of the subnet class type.
int numBitsBor;                  //the number of bits borrowed
int numSubnets;                  //the number of subnets
int numUseSubs;                  //the number of usable subnets
int numHostsPerSub;              //the total number of hosts per subnet
int useHostPerSub;               //the number of usable hosts per subnet
int totalHosts;                  //the total number of hosts
int totalUseHosts;               //the total number of usable hosts


char strIP [255];                //string for holding the IP address entered by the user

char strOct1 [4], strOct2 [4], strOct3 [4], strOct4 [4];    //string representation of each octet of the IP address
char strMask [3];                //string representation of the cider notation subnet mask

int  intOct1, intOct2, intOct3, intOct4;  //integer representation of each octet of the IP address
int  intMask;                    //integer representation of the cider notation subnet mask
int nOct1, nOct2, nOct3, nOct4;  //integer representation of each octet of the network address
int bOct1, bOct2, bOct3, bOct4;  //integer representation of each octet of the network broadcast address
int mOct1, mOct2, mOct3, mOct4;  //integer representation of each octet of the subnet mask address
int sOct1, sOct2, sOct3, sOct4;  //integer representation of each octet of the subnet address
int sBOct1, sBOct2, sBOct3, sBOct4;  //integer representation of each octet of the subnet broadcast address

int strIPLen;                    //the length of the IP address string entered by the user

int netBits;                     //number of bits in the network part of the IP address, used for calculating...
                                 //the number of bits borrowed

int index;                       //loop variable

int mask;                        //integer representation of the mask octet
//                                  ---VARIABLE DECLARATIONS---  end


//                                  ---INITIALIZE VARIABLES---  start
strIPLen=0;

nOct1=0;
nOct2=0;
nOct3=0;                            //set the starting values of the variables
nOct4=0;
bOct1=255;
bOct2=255;
bOct3=255;
bOct4=255;

netBits=0;

//                                  ---INITIALIZE VARIABLES---  end


//                                  ---GET THE IP ADDRESS---  start
// a prompt is printed for the user, then the function input is called.  The function returns the length of the
// string entered by the user.  The function takes the the string to which the input is saved and the max length
// of the string as parameters.

printf ("Enter the network IP: \n");  //print the prompt
//strIPLen = input (strIP, 255);        //get the IP address from the user
strcpy(strIP, "12.168.0.1/20");
strIPLen = 14;
//                                  ---GET THE IP ADDRESS---  end

//                                  ---CONVERT THE IP ADDRESS---  start
// next the ip address is parsed into each octet of the ip. then it is converted the integer values for
// calculations. The function parseOctet accepts the ip strings length, the ip string, and the octet variables.
// It converts the octets in the ip string to seperate octet strings.  These seperate octet strings are then
// converted to integer values using the standard c function: int atoi (char *);  The subnet mask is also
// converted using the same proccess.

parseOctet (strIP, strIPLen, strOct1, strOct2, strOct3, strOct4, strMask);  //parse the string IP address given
//by the user into seperate octets and mask, leaving out the .'s and /

intOct1=atoi (strOct1);
intOct2=atoi (strOct2);
intOct3=atoi (strOct3);  //convert the string representation of the octets to integer values
intOct4=atoi (strOct4);
intMask=atoi (strMask);  //convert the string representation of the mask to its integer value

if (intOct1>255 || intOct2>255 || intOct3>255 || intOct4>255 || intMask>30) {  //check the ip address to see
//if it has a valid range. each octet cannot be greater than 255.
printf ("Invalid IP address, out of range, or mask out of range"); //Print an error message and exit ...
exit (0);                                                     //the program if the values are out of range
}

//                                  ---CONVERT THE IP ADDRESS---  end


//                                  ---DETERMINE THE CLASS TYPE AND THE NETWORK ADDRESS---  start
//  The next step is to determine the type of class for the ip address.  The determineClass function accepts the first octet
//  of the ip address and returns a character representation of the class type.  Then the number of borrowed bits can be
//  determined based on the number of bits in the mask minus the number of network bits for the class type.  Then the network
//  and broadcast addresses are determined by setting the first octets to the first octets in the ip address.  How many octets
//  to use are determined by the class type. The broadcast and network octets were set to 0 and 255 when they were initialized
//  so the octets that were not set based on the class type are make them the broadcast and network address.  Then the class
//  type, the network address, and the network broadcast address are printed to the screen.

classType = determineClass (intOct1); //determine the class based on the first octet of the ip.
if (classType=='U') {  // the determine class function returns a U if the class is invalid
    printf ("Invalid Class\n"); //print the error message for an invalid class
    exit (0);//exit the program
}

if (classType=='A') netBits=8;
if (classType=='B') netBits=16;   //set the number of network bits based on the class type
if (classType=='C') netBits=24;

numBitsBor=intMask-netBits;       //the number of bits borrowed are equal to the number of bits in the mask minus the ...
                                  //number of number of network bits

if (numBitsBor<2) { //check that at least 2 bits must be borrowed to create a valid subnet mask
    printf ("Not enough bits borrowed, Invalid mask\n");  //print the error message
    exit (0); //exit the program
}

if (classType=='A') { // if the class type is A set the first one octet of the broadcast and network address to  the ...
    nOct1=intOct1;    // ip address.  The rest are all ready initialized to 0 or 255.
    bOct1=intOct1;
}
if (classType=='B') { // if the class type is B set the first two octets of the broadcast and network address to  the ...
    nOct1=intOct1;    // ip address.  The rest are all ready initialized to 0 or 255.
    bOct1=intOct1;
    nOct2=intOct2;
    bOct2=intOct2;
}
if (classType=='C') { // if the class type is C set the first three octets of the broadcast and network address to  the ...
    nOct1=intOct1;    // ip address.  The rest are all ready initialized to 0 or 255.
    bOct1=intOct1;
    nOct2=intOct2;
    bOct2=intOct2;
    nOct3=intOct3;
    bOct3=intOct3;
}


printf ("\nClass: %c\n",classType); //print the class type
printf ("Network ID: %i.%i.%i.%i \nNetwork Broadcast address: %i.%i.%i.%i\n",nOct1,nOct2,nOct3,nOct4,
bOct1,bOct2,bOct3,bOct4); // print the network address and the broacast address

//                                  ---DETERMINE THE CLASS TYPE AND THE NETWORK ADDRESS---  end


//                                           ---DETERMINE SUBNET MASK AND BROADCAST--- start
//  The subnet mask is calculated by setting the 1, 2, or 3 of the first octets to 255 based on the class.  Then for
//  class C addresses the last octet is calculated by the number of bits borrowed.  For a class B address, more than 8
//  bits can be borrowed. If more than 8 are borrowed the  3rd octet is set to 255 and the 4th octet is determined by
//  the bits left over, after the 8 that the 3rd octet used are subtracted.  If there is only 8 or fewer bits then the
//  3rd octet is determined by the number of bits borrowed and the 4th octet is set to 0.  For a class A more than 16
//  bits can be borrowed.  If 8 or less are borrowed then the the second octet is calculated for those bits and the 3rd
//  and 4th octet is set to 0.  If more than 8 and less than 16 are borrowed then the 2nd octet is set to 255 and the
//  third is set based on the bits left over; the 4th is set to 0.  If more than 16 bits are borrowed then the 2nd and
//  3rd octets are set to 255 to represent the first 16 bits borrowed and the 4th octet is calculated by the number of
//  bits left over.  The broadcast address is done in the same way except the octets that represent 8 bits are set to
//  the value of the corresponding octet of the ip address instead of 255.  The remaining bits are calculated by finding
//  the number of hosts per subnet from the number of bits borrowed and adding that to corresponding octet of the subnet
//  address which is found from binary anding the ip address and the subnet mask.


if (netBits==24) {  // if the ip address is a class c address then this section of code is used to determine the subnet mask...
                    // and the subnet broadcast address.
    mOct1=255;
    mOct2=255;      // Set the first three octets of the subnet mask to 255 becuase a class c subnet mask allways starts with...
    mOct3=255;      // 255.255.255

    sBOct1=intOct1;
    sBOct2=intOct2; // Set the first three octets of the broadcast address to the ip address because they will be the same in...
    sBOct3=intOct3; // a class C address.

    mask=deterMask (numBitsBor); //set a temporary mask variable to what is returned by the deterMask function.  The deterMask
                                 //function takes a number of bits and finds the mask number based on those bits.

    mOct4=mask;                  //Set the 4th octet to the mask number.

    sBOct4=deterSubBroad (numBitsBor,intOct4 & mask); //Set the 4th octet of the subnet broadcast address to what is returned...
    //by the deterSubBroad function.  This function takes the number of bits borrowed, the 4th octet of the ip which was BINARY...
    //ANDED to the temporary mask variable, which gives the fourth octet of subnet address.  The function calculates the ...
    //broadcast by adding the number of addresses in the subnet based on the bits borrowed to the subnet address.
    }//netBits==24

if (netBits==16) { // if the ip address is a class B address then this section of code is used to determine the subnet mask...
                    // and the subnet broadcast address.

    mOct1=255;// Set the first two octets of the subnet mask to 255 becuase a class b subnet mask allways starts with 255.255
    mOct2=255;

    sBOct1=intOct1;// Set the first two octets of the broadcast address to the ip address because they will be the same in a...
    sBOct2=intOct2;// class b address.

    if (numBitsBor<=8) {// Here we check to see if the mask takes up more than one octet more than the network address, since...
                        // the number of bits borrowed are less than 8 we find the subnet mask based on a mask with just one...
                        // octet more than the network address. We didn't do this for the class c address because it can...
                        // only have a mask with one octet.

        mask=deterMask (numBitsBor); //The significant number of the mask is determined by the deterMask function, based on...
                                     //the number of bits borrowed.  This number is significant because the first octets are...
                                     //just 255, and the octets after it are 0.

        mOct3=mask;                  // The third octet is set to the significant part of the mask.
        mOct4=0;                     // The 4th octet is set to 0.

        sBOct3=deterSubBroad (numBitsBor,intOct3 & mask); //Set the 4th octet of the subnet broadcast address to what is returned...
                                                          //by the deterSubBroad function.

        sBOct4=255;  // Set the 4th octet of the broadcast address to 255 since it was the 3rd octet which was significant.
        }//numBitsbor<8
        else
        if (numBitsBor<=16) { // Here we check to see if the mask takes up more than one octet more than the network address, since...
                              // the number of bits borrowed are more than 8 we find the subnet mask based on a mask with 255 for...
                              // the first octet of the bits borrowed, and calculate the remaining number of bits borrowed.

        mOct3=255; // Set the third octet to 255 since all eight of these bits borrowed are 1's.
        mask=deterMask (numBitsBor-8);  // Determine the rest of the mask based on the number of bits borrowed minus 8 because
                                        // those 8 were taken in the 3rd octet.

        mOct4=mask; // Set the 4th octet to this temporary mask.

        sBOct3=intOct3; // Set the 3rd octet of the subnet broadcast address to the third octet of the ip address.
        sBOct4=deterSubBroad (numBitsBor-8,intOct4 & mask); // Determine the 4th octet of the broadcast address by taking the number...
                                                            // of bits borrowed minus the 8 that were taken by the 3rd octet.  And...
                                                            // taking the 4 octet of the subnet address, which is found by anding the...
                                                            // 4th octet of the ip address and the 4 octet of the subnet mask.
        }
}// if netBits=16


if (netBits==8) { // if the ip address is a class A address then this section of code is used to determine the subnet mask...
                  // and the subnet broadcast address.

    mOct1=255;  // Set the first octet of the subnet mask to 255 becuase a class a subnet mask allways starts with 255

    sBOct1=intOct1;// Set the first octet of the broadcast address to the ip address because they will be the same in a ...
                   // class A address.


    if (numBitsBor<=8) {  // if the number of bits borrowed is 8 or less then we only need take in account the 2nd octet.
        mask=deterMask (numBitsBor); // find the mask based on the number of bits borrowed.
        mOct2=mask;  // Set the second octet of the subnet mask to the mask that was calculated.
        mOct3=0;  // Set the third and fourth octets to 0 because the subnet masked started in the second octet and only...
        mOct4=0;  // used 8 bits.

        sBOct2=deterSubBroad (numBitsBor,intOct2 & mask); // Determine the significant octet broadcast address based on the...
                                                          // number of bits borrowed and the 2nd octet of the subnet address.

        sBOct3=255; // Set the 3rd and 4th octets of the broadcast address to 255.
        sBOct4=255;

    }//numBitsbor<8
        else
        if (numBitsBor<=16) { // Sf the number of bits are greater than 8 and less than 16 then we need to set the second octet...
                              // to 255 and calculate the 3rd octet based on the number of bits borrowed minus the 8 that the ...
                              // second octet used.
        mOct2=255;
        mask=deterMask (numBitsBor-8);
        mOct3=mask;
        mOct4=0;              // Set the 4th octet to 0.

        sBOct2=intOct2; //  Since the more than 8 bits are borrowed we need to set the 2nd octet of the broadcast address to the...
                        //  sendcond octet of the ip address and use the remaining bits to find the 3rd octet of the broadcast address.
        sBOct3=deterSubBroad (numBitsBor-8,intOct3 & mask);  //The significant part of the broadcast address is calculated.
        sBOct4=255;  // Set the 4th octet of the broadcast address to 255.

        }// numBitsBor<16
            else  // If more than 16 bits were borrowed this means that the first comes from the network address the next two are 255...
                  // to represent the first 16 bits and the 4th octet is calculated from the remaining bits.
            {
            mOct2=255;  //Set the 2nd and 3rd octet to 255 to represent the first 16 bits borrowed.
            mOct3=255;
            mask=deterMask (numBitsBor-16); // Calculate the 4th octet based on the number of bits left over.
            mOct4=mask;

            sBOct2=intOct2;  // Set the 2nd and third Octets of the broadcast address to the 2nd and 3rd octets of the ip address to account...
            sBOct3=intOct3;  // for the first 16 bits borrowed.
            sBOct4=deterSubBroad (numBitsBor-16,intOct4 & mask); // Determine the 4th octet of the broadcast address based on the number of...
                                                                 // bits left over.
            }//numBitsBor<
}// if netBits=8;
//                                           ---DETERMINE SUBNET MASK AND BROADCAST--- end


printf ("\nSubnet Mask: %i.%i.%i.%i\n",mOct1,mOct2,mOct3,mOct4);  //print the subnet mask to the screen.
sOct1=intOct1 & mOct1; // calculate the first octet of the subnet address by anding the first octet of the ip address and the first
                       // octet of the subnetmask.
sOct2=intOct2 & mOct2;// calculate the 2nd octet of the subnet address by anding the 2nd octet of the ip address and the 2nd octet of...
                       // the subnetmask.
sOct3=intOct3 & mOct3;// calculate the 3rd octet of the subnet address by anding the 3rd octet of the ip address and the 3rd octet of...
                       // the subnetmask.
sOct4=intOct4 & mOct4;// calculate the 4th octet of the subnet address by anding the 4th octet of the ip address and the 4th octet of...
                       // the subnetmask.
printf ("Subnet Address: %i.%i.%i.%i\n",sOct1,sOct2,sOct3,sOct4);  // Print the subnet address.
printf ("Subnet Broadcast Address: %i.%i.%i.%i\n",sBOct1,sBOct2,sBOct3,sBOct4);// Print the subnet broadcast address.


//                                           ---CALCULATE THE NUMBER OF SUBNETS AND HOSTS PER SUBNET--- start
//  The number of subnets is calculated by setting it to 2 and multiplying it by 2 for every number of bits borrowed.  This is the same as 2
//  to the n power, where n is the number of bits borrowed.  The number of usable subnets is found by subtracting the 2 from the number of
//  subnets.  The number of hosts per subnet is calculated by setting it to 2 and multiplying it by 2 for every bit int the ip address minus
//  the number of bits in the mask.  The usable hosts are calculated by subtracting 2 from the number of hosts.  The total number of hosts is
//  calculated by multiplying the number of hosts by the number of subnets and the total usable hosts is found by multiplying the number of
//  usable hosts per subnet by the number of usable subnets.

numSubnets=2;// Set the number of subnets to 2.
for (index=1;index<numBitsBor;index++) {  // Loop for the number of bits borrowed -1 times.
    numSubnets=numSubnets*2; //Multiply the number of subnets to 2;
    }
numUseSubs=numSubnets-2; //Subtract 2 from the number of subnets to find the number of usable subnets.

numHostsPerSub=2;//  Set the number of hosts per subnet to 2;
for (index=1;index<32-intMask;index++) { // Loop for the number of bits in an ip address minus the number of bits in the mask.

    numHostsPerSub=numHostsPerSub*2; // Multiply the number of hosts per subnet by 2;
    }
useHostPerSub=numHostsPerSub-2; // Subtract 2 from the number of hosts per subnet to find the number of usable hosts per subnet.

totalHosts=numHostsPerSub*numSubnets; // Calculate the total number of hosts by multiplying the number of hosts per subnet by the number of subnets.
totalUseHosts=useHostPerSub*numUseSubs; // Calculate the totall number of usable hosts by multiplying the number of usable hosts per subnet by the
                                        //number of usable subnets.
//                                           ---CALCULATE THE NUMBER OF SUBNETS AND HOSTS PER SUBNET--- end




printf ("\nNumber of bits borrowed: %i\n",numBitsBor); // Print the number of bits borrowed
printf ("Number of subnets created: %i ; usable subnets: %i\n", numSubnets, numUseSubs); // Print the number of subnets created and the number
                                                                                         //of usable subnets.
printf ("Number of hosts per subnet: %i ; usable hosts per subnet %i\n",numHostsPerSub, useHostPerSub);// Print the number of host per subnet
                                                                                                       //and the usable hosts per subnet.
printf ("Total Hosts: %i ; Total usable Hosts: %i\n",totalHosts, totalUseHosts); // Print the total hosts and the total usable hosts.
printf ("\n\nPress enter to continue");// Prompt user to press enter when done
index = input (strIP, 255);        //Wait for user to press enter.

setbuf(stdin, 0);
getchar();
}// main

//                                           ---DETERMINE THE MASK--- start
//  This function accepts and integer and returns an integer.  It finds the mask number by adding 128 to a temp number and then adding half of what it added before for each...
//  of the number of bits passed to it.
int deterMask (int mask) {
    int index;  // loop variable.
    int increment; // amount to add to mask.
    int tmp; // temp variable for the mask.
    tmp=0; // initialize the temp variable to 0.
    increment=128;// initialize the amount to add to 128.
    for (index=0;index<mask;index++) { //Loop for the number of times passed to this funciton.
        tmp=tmp+increment; // and the increment variable to the temp variable.
        increment=increment/2; // divide the increment variable by 2.
    }
    mask=tmp;// Set the mask to the temp variable.
    return (mask); // Return the mask.
}
//                                           ---DETERMINE THE MASK--- end


//                                           ---DETERMINE THE SUBNET BROADCAST OCTET--- start
//  This function accepts the number of bits borrowed by the subnet mask and the subnet address.  It calculates the number of hosts in a subnet by raising 2 to the power of n...
//  where n is equal to the number of bits left for hosts.  The number of bits left for hosts is found by subtracting the number of bits borrowed for the subnet address from 8.
//  It then adds the number of hosts to the subnet address and subtracts 1 to find the broadcast address.

int deterSubBroad (int btsbrd, int mask) {
int broad; // The broadcast variable.
int index; // Loop variable.
broad=2; // Initalize the broadcast variable to 2.
for (index=1;index<8-btsbrd;index++) { //loop from 1 to 8 minus the number of bits borrowed, incrementing by 1
broad=broad*2;// multiply the broadcast by 2;
}
broad = mask + broad -1;// Set the broadcast to the mask plus the broadcast amount minus 1.
return (broad);// return the broadcast amount.
}
//                                           ---DETERMINE THE SUBNET BROADCAST OCTET--- end


//                                           ---DETERMINE THE CLASS--- start
//  The class is determined by a set of if statements that set the classType variable based on the ip address.
//  It accepts the first oct of the ip address as an int, and returns the class type as a character.

char determineClass (int Oct1) { // function for determining the class.
    char classType; // class type variable
    classType = 'U'; // Set the class type to invalid.
    if (Oct1>=1 && Oct1<=126) classType='A'; // if the ip is greater than 0 and less than 127 set the class type to A
    if (Oct1>=128 && Oct1<=191) classType='B'; // if the ip is greater than 127 and less than 192 set the class type to B
    if (Oct1>=192 && Oct1<=223) classType='C'; // if the ip is greater than 191 and less than 224 set the class type to C
    return (classType); // Return the class type.
}
//                                           ---DETERMINE THE CLASS--- end


//                                           ---PARSE THE IP STRING--- start
//The IP string is parsed by 5 while loops, that loop from the beginning of the string index to the end.
//The characters of the ip string are copied to the octet strings.  The index variable for the ip string...
//is kept incrementing through to the end of the string.  The index variable for the octet strings is...
//reset to 0 to start the next octet string at the begining of its array.  Each loop stops when the...
//current character is a . or the index for the ip string is longer than the lenght of the ip string, or...
//the index of the octet string is longer than the length of the octet string. Then the ip is checked to...
//see if it stopped on the right char, to tell if it was a valid ip or not.  Then the next octet loop...
//starts, finishing with a mask loop.

void parseOctet (char *strIP, int strIPLen, char *strOct1, char *strOct2, char *strOct3, char *strOct4, char *strMask) {
int index; //Loop variable.
int a; //temp index variable
index=0; //Initialize index to 0
a=0;  //Initialize a to 0

while ((strIP[index]!='.') && (index<strIPLen) && (a<3)) { //loop through the char array until an . is found...
//or the index variable is greater than the length of the string or the index variable for the Octet string...
//is greater than 3

strOct1[a++]=strIP[index++]; //Set the octet string to the character in the IP string.
}// while strIP[index]

if (strIP[index]!='.') { //Check to see if the loop stopped on a . if not it is an invalid ip address.
printf ("Invalid IP address, enter in xxx.xxx.xxx.xxx/xx format\n"); //Print the error message.
exit (1); // Exit the program.
}// if (strIP[index]!='.'
index++; // add 1 to the index variable to skip the . for the next octet.
strOct1[a]='\0'; //add the null character to the end of the octet string.

a=0;// initialize a to 0 to get ready for parsing the next octet.
while ((strIP[index]!='.') && (index<strIPLen) && (a<3)) { //loop through the char array until an . is found...
//or the index variable is greater than the length of the string or the index variable for the Octet string...
//is greater than 3

strOct2[a++]=strIP[index++]; //Set the octet string to the character in the IP string.
}// while strIP[index]
if (strIP[index]!='.') { //Check to see if the loop stopped on a . if not it is an invalid ip address.
printf ("Invalid IP address, enter in xxx.xxx.xxx.xxx/xx format\n"); //Print the error message.
exit (1); // Exit the program.
}// if (strIP[index]!='.'
strOct2[a]='\0';//add the null character to the end of the octet string.
index++;// add 1 to the index variable to skip the . for the next octet.

a=0; // initialize a to 0 to get ready for parsing the next octet.
while ((strIP[index]!='.') && (index<strIPLen && a<3)) {//loop through the char array until an . is found...
//or the index variable is greater than the length of the string or the index variable for the Octet string...
//is greater than 3.
strOct3[a++]=strIP[index++]; //Set the octet string to the character in the IP string.
}// while strIP[index]
if (strIP[index]!='.') { //Check to see if the loop stopped on a . if not it is an invalid ip address.
printf ("Invalid IP address, enter in xxx.xxx.xxx.xxx/xx format\n"); //Print the error message.
exit (1); // Exit the program.
}//if (strIP[index]!='.'
strOct3[a]='\0';//add the null character to the end of the octet string
index++;// add 1 to the index variable to skip the . for the next octet.

a=0;// initialize a to 0 to get ready for parsing the next octet.
while ((strIP[index]!='/') && (index<strIPLen && a<3)) { //loop through the char array until an . is found...
//or the index variable is greater than the length of the string or the index variable for the Octet string...
//is greater than 3.
strOct4[a++]=strIP[index++];//Set the octet string to the character in the IP string.
}// while strIP[index]
if (strIP[index]!='/') {//Check to see if the loop stopped on a / if not it is an invalid ip address.
printf ("Invalid IP address, enter in xxx.xxx.xxx.xxx/xx format\n");//Print the error message.
exit (1); // Exit the program.
}
strOct4[a]='\0';//add the null character to the end of the octet string
index++;// add 1 to the index variable to skip the / for the mask.

a=0;// initialize a to 0 to get ready for parsing the next octet.
while ((strIP[index]!='\0') && (index<strIPLen && a<2)) {//loop through the char array until a null character...
//is found or the index variable is greater than the length of the string or the index variable for the Octet...
//string is greater than 2.
strMask[a++]=strIP[index++];//Set the mask string to the character in the IP string.
}// while strIP[index]
if (strIP[index]!='\0') {//Check to see if the loop stopped on a null character if not it's an invalid address.
printf ("Invalid IP address, enter in xxx.xxx.xxx.xxx/xx format\n"); //Print the error message.
exit (1); // Exit the program.
}
strMask[a]='\0';//add the null character to the end of the mask string

//The values of the octet strings are kept when the function finishes because they were passed by loops.
}
//                                           ---PARSE THE IP STRING--- end


//                                           ---INPUT--- start
//  This function sets a string to what is enter in the keyboard until the return key is pressed.  It accepts...
//  a string to put the keyboard data in, and the length of the string.  It returns the number of chars that...
//  were entered.

int input (char *string, int lenOfStr) { //Input function.
int index; // Loop variable.
int letter; //  Variable to hold the key pressed.
index=0; // Initialize the index to 0.
while ((letter = getchar())!='\n' && (index<(lenOfStr-1))) { // Loop untill the retrun key is pressed or the
//number of chars entered is greater than the length of the string. Get a character from the keyboard each
//time through the loop and set letter to its value.

*string++ = letter; //Add the character to the string.
index++;// Increment the index.
}
*string='\0';//Add the null character to the end of the string.
return (index); // return the length of the string.
}//input
//                                           ---INPUT--- end
