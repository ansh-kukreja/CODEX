import java.awt.*;
import java.awt.event.*;
public class MiniCalc extends Frame implements ActionListener{

TextField t1,t2,t3;
Button b1,b2,b3,b4,b5;
MiniCalc()
{
Label l1=new Label("Enter 1st no");
Label l2=new Label("Enter 2nd no");
Label l3=new Label("Results ");
t1=new TextField();
t2=new TextField();
t3=new TextField();
b1=new Button("ADD");
b2=new Button("SUB");
b3=new Button("Multi");
b4=new Button("DIV");
b5=new Button("MOD");
l1.setBounds(50,100,100,30);
l2.setBounds(50,140,100,30);
l3.setBounds(50,180,100,30);
t1.setBounds(200,100,100,30);
t2.setBounds(200,140,100,30);
t3.setBounds(200,180,100,30);
b1.setBounds(50,250,60,30);
b2.setBounds(110,250,60,30);
b3.setBounds(180,250,60,30);
b4.setBounds(240,250,60,30);
b5.setBounds(290,250,60,30);
add(l1);
add(l2);
add(l3);
add(t1);
add(t2);
add(t3);
add(b1);
add(b2);
add(b3);
add(b4);
add(b5);
setVisible(true);
setSize(500,500);
b1.addActionListener(this);
b2.addActionListener(this);
b3.addActionListener(this);
b4.addActionListener(this);
b5.addActionListener(this);
}
public void actionPerformed(ActionEvent e)
{
int n1=Integer.parseInt(t1.getText());
int n2=Integer.parseInt(t2.getText());
if(e.getSource()==b1)
{
t3.setText(String.valueOf(n1+n2));
}
if(e.getSource()==b2)
{
t3.setText(String.valueOf(n1-n2));
}

}
public static void main(String ar[])
{
    MiniCalc obj=new MiniCalc();
}

}