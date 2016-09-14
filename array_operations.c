#include <stdio.h>
#include <stdlib.h>

void display_array(int arr[])
{
   int i;
   int n = sizeof(arr);

   for( i = 0; i < n; ++i )
   {
      printf("[%d]->[%d]\n",i, arr[i]);
   }
}

int insert_element_at_index(int arr[], int index, int value)
{
    int *tmpArr;
    int j;

    if ( index < 0 || arr == NULL || index > sizeof(arr) )
       return -1;

    tmpArr = &arr[0];

    tmpArr = realloc( tmpArr, (sizeof(arr) + 1) * sizeof(*tmpArr));

    j = sizeof(tmpArr);

    while( j >= index )
    {
         tmpArr[j+1] = tmpArr[j];
         j = j - 1;
    }
    
    tmpArr[index] = value;
    return 0;
}

int delete_element_by_index(int arr[], int index)
{
    int *tmpArr;
    int j = index;

    if( index < 0 || arr == NULL || index > sizeof(arr))
        return -1;

    tmpArr = &arr[0];

    while ( j < sizeof(arr) )
    {
       tmpArr[j-1] = tmpArr[j];
       j = j + 1;
    }

    tmpArr = realloc( tmpArr, (sizeof(arr) - 1) * sizeof(*tmpArr) );
    return 0;
}

int update_element_by_index(int arr[], int index, int value)
{
    if( index < 0 || arr == NULL || index > sizeof(arr))
        return -1;

    arr[index] = value;
    return 0;
}

int search_element_by_value(int arr[], int value)
{
    int j;

    if( arr == NULL )
      return -1;

    for( j= 0; j < sizeof(arr), ++j )
    {
       if( arr[j] == value )
          break;
    }
  
    if (j == sizeof(arr))
       return 0;
    else
       return j;
}

int main()
{
  return 0; 
} 
