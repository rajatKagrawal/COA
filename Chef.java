import java.util.*;
import java.lang.*;
import java.io.*;

class Chef
{
	public static void main (String[] args) throws java.lang.Exception,IOException
	{
		
		 BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
		 int t=Integer.parseInt(read.readLine());
		
	    		for(int k=1;k<=t;k++)
			 {
			 int count=0;
    			 int n,i,temp;
    			 int length,j; 
		          n=Integer.parseInt(read.readLine());
   			 for(i=n;i>0;i--)
    				{
        			temp=i;
        			count=0;
        			length=fnlen(i);
        			for(j=1;j<length;j++)
        			{
            				int x=temp%10;
           				 temp=temp/10;
            				int y=(temp)%10;
            				if(x>=y)
            				{
            					count++;
            				}
            				else
                			break;
        			}
        			if(count==length-1)
        			{
         			System.out.println("case #"+k+": "+i);
       				  break;
        			}
  			}				
		} 
	}


	public static int fnlen(int val)
	{
    		int length=0;
    		while(val!=0)
    		{
        		val=val/10;
    		        length++;
    		}
    		return length;
	}
	
	

}
