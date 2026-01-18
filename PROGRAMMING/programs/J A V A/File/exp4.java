import java.util.Scanner;

public class exp4
{
	String name, rollno, city, phone, branch;
    float cgpa;
    static Scanner s1 = new Scanner(System.in);
    void get(int n) 
    {
    	System.out.println("Enter Details of Student No"+(n+1)+":");
        System.out.println("Enter the Name:");
        name = s1.next();
        System.out.println("Enter Roll No:");
        rollno = s1.next();
        System.out.println("Enter City:");
        city = s1.next();
        System.out.println("Enter Phone no:");
        phone = s1.next();
        System.out.println("Enter Branch:");
        branch = s1.next();
        System.out.println("Enter CGPA:");
        cgpa = s1.nextFloat();
        System.out.println("--------------------------------------------------");
    }
    void display() 
    {
        System.out.println("Name is:" + name + "\nRoll Number is:" + rollno + "\nCity is:" + city + "\nPhone no is:" + phone + "\nBranch is:" + branch + "\nCGPA is:" + cgpa);
        System.out.println("--------------------------------------------------");
    }

    static void query1(exp4[] e1) 
    {
    	char ch;
	  	int count=0;
	  	System.out.println("Enter the character:");
	  	ch=s1.next().charAt(0);
	  	for(int i=0;i<e1.length;i++) 
	  	{
		  	if(e1[i].name.charAt(0)==ch) 
		  	{
			  	count++;
		  	}
	  	}
	  	System.out.println("Number of students whose name starts with "+ ch+ " are: "+count);
	  	System.out.println("--------------------------------------------------");
    }

    static void query2(exp4[] e1) 
    {
    	System.out.println("Enter the city: ");
    	String temp=s1.next();
    	for(int i=0;i<e1.length;i++) 
    	{
    		if((e1[i].city).equals(temp) && e1[i].cgpa>8.0) 
    		{
    			System.out.println("Details Students Whose City is "+temp+" and CGPA is Greater than 8.0 are:");
    			e1[i].display();
    		}
    	}
    	System.out.println("--------------------------------------------------");
  	}

  	static void query3(exp4[] e1) 
  	{
  		int count;
  		for(int i=0;i<e1.length;i++) 
  		{
			if(e1[i].branch.equals(" ")) {
				continue;
			}
			String temp=e1[i].branch;
			count=1;
			for(int j=i+1;j<e1.length;j++) 
			{
				if(e1[j].branch.equals(temp)) 
				{
					count++;
					e1[j].branch=" ";
				}
			}
			System.out.println("Number of students belonging to "+temp+ " branch are:"+ count);
		}
  		System.out.println("--------------------------------------------------");
	}

    public static void main(String ar[]) 
    {
    	System.out.println("Gauraansh, 2210997081, Exp4");
        System.out.println("Enter number of Students: ");
        int n = s1.nextInt();
        exp4[] e1 = new exp4[n];
        for (int i = 0; i < n; i++) 
        {
            e1[i] = new exp4();
            e1[i].get(i);
        }
        for (int i = 0; i < n; i++) 
        {
            e1[i].display();
        }
        while(true) 
        {
        	System.out.println("Enter option \n 1. Search based on first character of name.\n 2. Details for student who belong to a particular city and CGPA more than 8.0 .\n 3. Count similar branch students.");
        	int c=s1.nextInt();
        	switch(c) 
        	{
        	case 1: 
        		query1(e1);
        		break;
        	case 2: 
        		query2(e1); 
        		break;
        	case 3:
        		query3(e1); 
        		break;
        	}
        	System.out.println("Want to continue y for yes and n for no:");
        	char ch=s1.next().charAt(0);
        	if(ch=='n')break;
        }
        System.out.println("--------------------------------------------------");
    }
}