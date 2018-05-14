public class Main {

    public static int daten[] = {1, 2, 3, 7, 0};

    public static void main(String[] args) {
        sort(0,daten.length-1);

        for(int i : daten){
            System.out.println(i);
        }
    }

    public static void sort(int left, int right){
        if(left < right){
            int teile = split(left,right);
            sort(left,teile);
            sort((teile+1),right);
        }
    }

    public static int split(int left, int right){
        int i = left;
        int j = right-1;
        int pivot = daten[right];

        do{
            while(daten[i] < pivot && i < right-1){
                i++;
            }
            while(daten[j] >= pivot && j > left){
                j--;
            }
            if(i < j){
                int tmp = daten[i];
                daten[i] = daten[j];
                daten[j] = tmp;
            }
        }while(i < j);
        if(daten[i] > pivot){
            int tmp = daten[i];
            daten[i] = daten[right];
            daten[right] = tmp;
        }
        return i;
    }
}
