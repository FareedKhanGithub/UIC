#include "symbolTable.h"

// Top should point to the top of the scope stack,
// which is the most recent scope pushed

SymbolTableStackEntryPtr symbolStackTop;

int scopeDepth;
/* global function prototypes */
//allocate the global scope entry and symbol table --and set scopeDepth to 0
// The global scope remains till the end of the program
      // return 1 on success, 0 on failure (such as a failed malloc)

int hash_function(char*h){
    int part;
    int i;
    for(i = 0;i<strlen(h);i++){
        part += h[i];
    }
    
    int sum = part% MAXHASHSIZE;
    return sum;
}






int	initSymbolTable()       //The first case
{
     //malloc for some type of object in place        //was not renamed  with typedef therefore struct
     SymbolTableStackEntryPtr p  = (SymbolTableStackEntryPtr)malloc(sizeof(struct symbolTableStackEntry));
     if(p == NULL){
         return 0;
     }
          
     p-> prevScope = NULL;         //this pointter is from above SymbolTableStackEntryPtr
     p -> symbolTablePtr = (SymbolTablePtr)malloc(sizeof(struct symbolTable));
     if(p -> symbolTablePtr == NULL){
         return 0;
     }
         
     symbolStackTop = p;        //so now to access symbolTableEntryptr    we make  p equal to symbolsttop 
                                           //they are same name 
     scopeDepth = 0; 
     
}


// Look up a given entry 
ElementPtr symLookup(char *name)
{
                  //k allows you to step back and point at particular things you want 
        
    ElementPtr k = symbolStackTop->symbolTablePtr->hashTable[hash_function(name)];    // This is what k is going to specific go into the hash element
                                                                                              //name
    if(k != NULL){                           //need to make sure k is not null 
        while(k-> next != NULL){    
             if(name == k ->id){          
                printf("is found");
                ElementPtr product = k;        //when both are pointers just make them equal to eachother to symbolize as one of the same
                return product;         //we will be needing this pointer from the library to access that specific name
                }   
                                    //if while breaks then  proceed onto the next p
            }
    if(k->next == NULL){     //if next is NULL then go to previous element in the stack
        symbolStackTop->prevScope->symbolTablePtr->hashTable[hash_function(name)];   
                                                          //the idea here is to p to prevscope to minisym to ha      
        }           
    }
    else{      //if all stacks are done and hash tables been searched and all linked list been searched then return NULL;                                          
        return NULL;
    }
}




// Insert an element with a specified type in a particular line number
// initialize the scope depth of the entry from the global var scopeDepth
ElementPtr symInsert(char *name, struct type *type, int line)
{
    //build element and populate it
    ElementPtr k = malloc(sizeof(Element));

    k-> id = name;                               
    k-> key = hash_function(name);          //hash_function   key is how the number inside of traversing
    k-> linenumber=line;
    k-> next = NULL;
    k-> scope = scopeDepth;
    k-> stype = type;

    // Check if hashTable[i] is empty
    if(symbolStackTop->symbolTablePtr->hashTable[k->key] == NULL){
        symbolStackTop->symbolTablePtr->hashTable[k->key] = k;  
}
    // If it is not
    else
    {
        HashTableEntry i = symbolStackTop->symbolTablePtr->hashTable[k->key];
        // Move towards the end of the list and Insert
        while(i->next != NULL)
        {
            i = i->next;
        }

        i->next=k;
    }
}








//push a new entry to the symbol stack
// This should modify the variable top and change the scope depth
// return 1 on success, 0 on failure (such as a failed malloc)
int	enterScope()       
{
    SymbolTableStackEntryPtr p  = (SymbolTableStackEntryPtr)malloc(sizeof(struct symbolTableStackEntry));
     if(p == NULL){
         return 0;
     }
     
     p-> prevScope = symbolStackTop;       //this allows ability to point to top then to old node
                                                // the reason why it so has the ablity to go back
                                                     //make a sort of hash table                                    
     p -> symbolTablePtr = (SymbolTablePtr)malloc(sizeof(struct symbolTable));
     if(p -> symbolTablePtr == NULL){
         return 0;
     }

     symbolStackTop = p;        //so now to access symbolTableEntryptr    we make  p equal to symbolsttop 
                                           //they are same name 
     scopeDepth++;       //this will increment the number of scope depth 
}







//pop an entry off the symbol stack
// This should modify top and change scope depth


void leaveScope()                          
{     
    int name;
    SymbolTableStackEntryPtr p  = (SymbolTableStackEntryPtr)malloc(sizeof(struct symbolTableStackEntry)); 

    for(name = 0;name < MAXHASHSIZE;name++){
    ElementPtr w = symbolStackTop->symbolTablePtr ->hashTable[name];
    ElementPtr q = symbolStackTop->symbolTablePtr ->hashTable[name];
        if(w != NULL){    
        while(w-> next !=NULL && w->next != NULL){    
            q = w -> next;
            free(w);  
            w = q;
        }
    }
    }
     free(symbolStackTop->symbolTablePtr->hashTable);
     free(symbolStackTop->symbolTablePtr);
     
     //ElementPtr t = symbolStackTop;
     SymbolTableStackEntryPtr t = symbolStackTop;
     SymbolTableStackEntryPtr x = symbolStackTop->prevScope;
     if(symbolStackTop->symbolTablePtr == NULL){
        free(t);
     }  
      
    symbolStackTop = p;        //so now to access symbolTableEntryptr    we make  p equal to symbolsttop                                                                 
    scopeDepth--;                    
}










////////////////////////////////////////////////////////////////////////////////////////////////////
// Do not modify this function
void printElement(ElementPtr symelement) {
    if (symelement != NULL) {
        printf("Line %d: %s", symelement->linenumber,symelement->id);
    }
    else printf("Wrong call! symbol table entry NULL");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////



            
//should traverse through the entire symbol table and print it
// must use the printElement function given above
void printSymbolTable()
{
    
}
