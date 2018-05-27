public class Bubblesort {

	public static int[] bubblesort(int[] array)
	{
		if(array.length == 1)
		{
			return array;
		}
		else
		{
			int laenge = array.length-1;
			int temp;
			for(int i=0; i<array.length; i++)
			{
				for(int j=0; j<laenge; j++)
				{
					if(array[j] > array[j+1])
					{
						temp = array[j];
						array[j] = array[j+1];
						array[j+1] = temp;
					}	
				}
			laenge = laenge-1;
			}
			return array;
		}	
		
	}
	
	public static void main(String[] args)
	{
		int[] array = {4,3,8,6,2,1,6,10,9};
		
		System.out.print("Unsortiert:\t");
		for(int i=0; i<array.length; i++)
		{
			System.out.print(array[i] + "\t");
		}
		
		bubblesort(array);
		System.out.print("\nSortiert:\t");
		
		for(int i=0; i<array.length; i++)
		{
			System.out.print(array[i] + "\t");
		}
		
	}
	
}
