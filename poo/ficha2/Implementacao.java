package pacote;
import java.util.Arrays;

public class Implementacao{
    public int findMin(int[] array){
        int min = array[0];
        for(int i = 1; i < array.length;i++){
            if(array[i] < min){
                min = array[i];
            }
        }
        return min;
    }
    public int[] window(int[] array,int a, int b){
        int size = b - a + 1;
        int[] window = new int[size];
        for(int i = 0;i < size;i++){
            window[i] = array[i + a];
        }
        return window;
    }
    public int[] common(int[] a,int[] b){
        int[] common;
        if(a.length > b.length){
            common = new int[a.length]; 
        }else{
            common = new int[b.length];
        }
        mergeSort(a,a.length);
        //printArray(a,a.length);
        mergeSort(b,b.length);
        //printArray(b,b.length);
        int index = 0;
        for(int i = 0;i < a.length;i++){
            for(int j = 0;j < b.length;j++){
                if(a[i] == b[j]){
                    int flag = 0;
                    for(int w = 0;w < common.length;w++){
                        if(a[i] == common[w]){
                            flag = 1;
                        }
                    }
                    if(flag == 0){
                        common[index] = a[i];
                        index++;
                    }
                }
            }
        }
        int[] real = new int[index + 1];
        for(int i = 0;i <= index;i++){
            real[i] = common[i];
        }
        return real;
    }
    public void mergeSort(int[] array,int length){
        mSortRecursion(array,0,length - 1);
    }
    private void mSortRecursion(int[] array,int l, int r){
        if(l < r){
            int m = l + (r - l) / 2;
            mSortRecursion(array,l,m);
            mSortRecursion(array,m + 1,r);

            mergeSortedArrays(array,l,m,r);
        }
    }
    private void mergeSortedArrays(int[] array,int l, int m, int r){
        // Get length of the right and left arrays
        int left_length = m - l + 1;
        int right_length = r - m;

        // Allocate memory for both the copy arrays
        int[] leftArray = new int[left_length];
        int[] rightArray = new int[right_length];


        // Copy the values from the original array that are present on the 
        // array the is on the left side of the comparison/division
        for(int i = 0;i < left_length;i++){
            leftArray[i] = array[l + i];
        }


        // Copy the values from the original array that are present on the 
        // array the is on the right side of the comparison/division
        for(int i = 0;i < right_length;i++){
            rightArray[i] = array[m + 1 + i];
        }

        // Variable i related to the left side
        // Variable j related to the right side
        
        // This cycle will iterate to every position of the arrays
        // comparing the values and inserting the smaller value on the 
        // original array
        int i,j,k;
        for(i = 0,j = 0, k = l; k <= r;k++){
            
            // Case where there are not elements on the left array
            // We'll just insert the ones remaining as they already are
            // sorted
            if(i == left_length && j < right_length){
                array[k] = rightArray[j];
                j++;
                continue;
            }

            // Case where there are not elements on the right array
            // We'll just insert the ones remaining as they already are
            // sorted
            if(i < left_length && j == right_length){
                array[k] = leftArray[i];
                i++;
                continue;
            }


            // Main comparison: 
                // if 
                    // there are elements on the left AND 
                        // no more on the right OR the left element is less than the right
                // 
            if((i < left_length) && (j >= right_length || leftArray[i] <= rightArray[j])){
                array[k] = leftArray[i];
                i++;
            }else{
                array[k] = rightArray[j];
                j++;
            }

        }
    }
    public void printArray(int[] array,int size){
        if(size > 1){
            System.out.print("[ " + array[0]);
            for(int i = 1;i < size;i++){
                System.out.print(" -> " + array[i]);
            }
            System.out.println(" ]");
            return;
        }
        if(size == 1){
            System.out.println("[ " + array[0] + " ]");
            return;
        }
    }
}