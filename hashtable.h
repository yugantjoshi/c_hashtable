#ifndef count_h
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include <string.h>


typedef struct ListNode{
  long data;
  struct ListNode *next;
} ListNode;
typedef struct hash
{
  ListNode *root;
  int numElements;
} Hash;

Hash *hashTable;
int size;

int getHashIndex(long decimalNum)
{
  int index = decimalNum%size;
  //printf("index %d\n\n", index);
  return index;
}
double getLoadFactor()
{
  //number of elements in hashtable/hash table length
  int i, count;
  double loadFactor;
  loadFactor = 0.0;
  count=0;
  for(i=0; i<size; i++)
  {
    count+=hashTable[i].numElements;
  }
  //printf("count %d\n", count);
  // loadFactor = (count*1.0)/(size*1.0);
  count =0;
  // printf("LOAD FACTOR %f\n", loadFactor);
  if(loadFactor>0.5)
  {
    return 1;
  }
  return 0;
}

void rehash(int index, long decimal)
{
  
}
int countUnique()
{
  int i,count;
  count =0;
  for(i=0; i<size;i++){
    count+=hashTable[i].numElements; 
 }
  return count;
}
int insertNode(int index, long decimal)
{
  ListNode* insert = (ListNode*)malloc(sizeof(ListNode));
  insert->data = decimal; 

  if(hashTable[index].root==NULL)
  {
    if(getLoadFactor()==1)
    {
      rehash(index, decimal);
      return 5;
      //insertNode(index, decimal);
     }
     // printf("initial insert at index %d\n", index);
    //beginning of linked list for hashtable[index]
    hashTable[index].root = insert;
    hashTable[index].numElements = 1;
    return 0;
  }
  else
  {
    ListNode* ptr = (ListNode*)malloc(sizeof(ListNode));
    ptr = hashTable[index].root;
    //printf("secondary insert at index %d\n", index);
    while(ptr!=NULL)
    {
      if(ptr->data == decimal)
      {
       return 0;
      }
      else if(ptr->next == NULL)
      {
	 if(getLoadFactor()==1)
	 {
          rehash(index, decimal);
          return 5;
	 }
        insert->next = hashTable[index].root;
        hashTable[index].root = insert;
        hashTable[index].numElements+=1;
        return 0;
      }
      ptr = ptr->next;
    }
  }
  return 0;
}


#endif
