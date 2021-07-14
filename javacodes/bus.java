

class bus
{
 int seats[] = new int[10];

public void booked(String owner,int seatNo)
{
try{
if(seats[seatNo]==1)
{
System.out.println("sorry seat number "+seatNo+" has been already booked");
}
else{
System.out.println("Seat number "+seatNo+" has been alloted to "+owner);
seats[seatNo]=1;
}
}
catch(ArrayIndexOutOfBoundsException e)
{
System.out.println(e);
}
}
}

class bookSeat extends Thread
{
String name;
int num;
bus b;

bookSeat(String n,int number,bus b)
{
name = n;
this.b = b;
num = number;
}

public void run()
{
synchronized(b)
{
b.booked(name,num);
}
}
}

class lab23
{
public static void main(String args[])
{
bus booking = new bus();
bookSeat t1 = new bookSeat("mike",5,booking);
bookSeat t2 = new bookSeat("jim",5,booking);
bookSeat t3 = new bookSeat("andy",5,booking);

t1.start();
t2.start();
t3.start();

try{
t1.join();
t2.join();
//t3.join();
}
catch(Exception e)
{
System.out.println("Inpterupted "+e);
}
}
}

