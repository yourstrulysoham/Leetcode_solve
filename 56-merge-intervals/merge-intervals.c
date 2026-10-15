/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(const void *a, const void *b)
{
    int *aa=*(int **)a;
    int *bb=*(int **)b;
    return aa[0]-bb[0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes)
{
    qsort(intervals,intervalsSize,sizeof(int*),cmp);

    int **retArr=(int **)malloc(intervalsSize*sizeof(int*));
    *returnColumnSizes=(int *)malloc(intervalsSize*sizeof(int));
    *returnSize=0;

    retArr[*returnSize]=(int *)malloc(2*sizeof(int));
    retArr[*returnSize][0]=intervals[0][0];
    int prevVal=intervals[0][1];

    for(int i=1;i<intervalsSize;i++)
    {
        if(retArr[*returnSize][0]>intervals[i][0]&&intervals[i][0]!=0)
        {
            retArr[*returnSize][0]=intervals[i][0];
        }
        if(prevVal<intervals[i][0])
        {
            retArr[*returnSize][1]=prevVal;
            (*returnColumnSizes)[*returnSize]=2;
            *returnSize+=1;
            
            retArr[*returnSize]=(int *)malloc(2*sizeof(int));
            retArr[*returnSize][0]=intervals[i][0];
            prevVal=intervals[i][1];
        }
        else if(prevVal<intervals[i][1])
        {
            prevVal=intervals[i][1];
        }
    }

    retArr[*returnSize][1]=prevVal;
    (*returnColumnSizes)[*returnSize]=2;
    (*returnSize)++;

    return retArr;
}