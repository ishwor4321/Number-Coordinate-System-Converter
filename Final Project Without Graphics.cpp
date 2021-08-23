#include<iostream>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<windows.h>
#include<bits/stdc++.h>
#include<sstream>
using namespace std;
class Converter
{
	private:
		int choice;
		
	public:
		void show_content()
		{
			cout<<"                                ****************** WELCOME TO CONVERTER ****************"<<endl;
			cout<<endl;
			cout<<endl;
			cout<<endl;
			cout<<"Here you can convert \n 1) Number \n 2) Coordinate"<<endl;
		}

};
class Digital_Converter: virtual public Converter
{
	private:
		int choice;
		void Convert_DecimalTo_Binary(int Decimal_Number)
		{
			int i=0, rem, BinaryDigit=0, temp=1;
			while(Decimal_Number>0)
			{
				rem=Decimal_Number%2;
				Decimal_Number/=2;
				BinaryDigit+=rem*temp;
				i++;
				temp*=10;
			}
			cout<<BinaryDigit;
			
		}
		void Convert_DecimalTo_Octal(int Decimal_Number)
		{
			int i=0, rem, OctalDigit=0, temp=1;
			while(Decimal_Number>0)
			{
				rem=Decimal_Number%8;
				Decimal_Number/=8;
				OctalDigit+=rem*temp;
				i++;
				temp*=10;
			}
			cout<<OctalDigit;
			
		}
		void Convert_DecimalTo_Hexadecimal(int Decimal_Number)
		{
			int i=0;
			int n=Decimal_Number;
			char hexaDecimal[100];
			while(n>0)
			{
				int temp=0;
				temp=n%16;
				if (temp<10)
				{
					hexaDecimal[i]=temp+48;
					i++;
			
				}
				else
				{
					hexaDecimal[i]=temp+55;
					i++;
				}
				n=n/16;
				}
			
			for (int j=i-1; j>=0; j--)
			{
				cout<<hexaDecimal[j];
			}
			
		}
		void Convert_DecimalTo_BCD(int Decimal_Number)
		{
			int n=Decimal_Number;
			if (n==0)
			{
				cout<<"0000";
		
			}
			int rev=0;
			while(n>0)
			{
				rev=rev*10+n%10;
				n/=10;
			}
			while (rev>0)
			{
				bitset<4> b(rev%10);
				cout<<b<<' ';
				rev/=10;
			}
			
		}
		void Convert_DecimalTo_GrayCode(int Decimal_Number)
		{
			int n=Decimal_Number;
			int GrayCode_Decimal=n^(n>>1);
			int i=0, rem, GrayCode_Digit=0, temp=1;
			while(GrayCode_Decimal>0)
			{
				rem=GrayCode_Decimal%2;
				GrayCode_Decimal/=2;
				GrayCode_Digit+=rem*temp;
				i++;
				temp*=10;
			}
			cout<<GrayCode_Digit;
			
	}
		void Convert_DecimalTo_Excess3Code(int Decimal_Number)
		{
			int i, rem, temp=0;
			int Number=Decimal_Number;
			int New_Number;
			while(Number>0)
			{
				Number/=10;
				temp=temp+1;
		
		
			}
			if(temp==1)
			New_Number=Decimal_Number+3;
			else if(temp==2)
			New_Number=Decimal_Number+33;
			else if(temp==3)
			New_Number=Decimal_Number+333;
			else if(temp==4)
			New_Number=Decimal_Number+3333;
			else if(temp==5)
			New_Number=Decimal_Number+33333;
			else if (temp==6)
			New_Number=Decimal_Number+333333;
			else if (temp==7)
			New_Number=Decimal_Number+333333;else
			cout<<endl;
			int n=New_Number;
			if (n==0)
			cout<<"0000";
			int rev=0;
			while(n>0)
			{
				rev=rev*10+n%10;
				n/=10;
			}
			while (rev>0)
			{
				bitset<4> b(rev%10);
				cout<<b<<' ';
				rev/=10;
			}
		}
		int Convert_Binary_To_Decimal(int Binary_Number)
		{
			int Decimal_Number=0, i=0, rem;
			int Converting_Binary_Number=Binary_Number;
			while(Converting_Binary_Number!=0)
			{
				rem=Converting_Binary_Number%10;
				Converting_Binary_Number/=10;
				Decimal_Number+=rem*pow(2,i);
				i++;
			}
			return Decimal_Number;
			
		}
		int Convert_Octal_To_Decimal(int Octal_Number)
		{
			int Decimal_Number=0, i=0, rem;
			while(Octal_Number>0)
			{
				rem=Octal_Number%10;
				Decimal_Number+=rem*pow(8,i);
				i++;
				Octal_Number/=10;
			}
			return Decimal_Number;
	
		}
		int Convert_Hexadecimal_To_Decimal(string hexDecNum)
		{
		
			int decimalNum=0, rem, i=0, len=0;
    		while(hexDecNum[i]!='\0')
    		{
        		len++;
        		i++;
    		}
    		len--;
    		i=0;
    		while(len>=0)
    		{
        		rem = hexDecNum[len];
       			if(rem>=48 && rem<=57)
            	rem = rem-48;
        		else if(rem>=65 && rem<=70)
            	rem = rem-55;
        		else if(rem>=97 && rem<=102)
            	rem = rem-87;
        		else
        			{
            			cout<<"\nInvalid Hex Digit!";
            			cout<<endl;
            			return 0;
        			}
        		decimalNum = decimalNum + (rem*pow(16, i));
        		len--;
       			 i++;
    			}
    		return decimalNum;
			
		}
		int Convert_BCD_To_Decimal(string s)
	{
    		int len = s.length(),
        	check = 0, check0 = 0;
    		int num = 0, sum = 0,
        	mul = 1, rev = 0;
			for (int i = len - 1; i >= 0; i--) 
			{
 				sum += (s[i] - '0') * mul;
       			mul *= 2;
        		check++;
 			if (check == 4 || i == 0) 
			 {
            	if (sum == 0 && check0 == 0)
				{
                	num = 1;
                	check0 = 1;
            	}
            	else 
				{
                	num = num * 10 + sum;
            	}
 			check = 0;
            sum = 0;
            mul = 1;
        	}
    	}
 		while (num > 0) 
		{
       		rev = rev * 10 + (num % 10);
        	num /= 10;
    	}
 		if (check0 == 1)
        	return rev - 1;
 		return rev;
	}
	int convertBinaryToDecimal(int n)
	{
		int decimalNumber = 0, i = 0, remainder;
    	while ( n!=0)
    	{
        	remainder = n%10;
        	n /= 10;
        	decimalNumber += remainder*pow(2,i);
        	++i;
    	}
 	return decimalNumber;
	}
	int Convert_GrayCodeDecimal(string gray)
	{
		string binary;
		binary = gray[0];
    	for (int i = 0; i < gray.length() - 1; i++)
    	{
        
        	if (binary[i] == gray[i+1])
            	binary = binary + "0";
       	 else
            	binary = binary + "1";
    	}
		string str=binary;
    	stringstream geek(str);
		int num;
		geek>>num;
		long long n;
    	n=num;
   		int Binaryeqv= convertBinaryToDecimal(num) ;
   		return Binaryeqv;
	}
	int Convert_Excess_3_Code_to_Decimal(int Decimal_Number)
{
	int i, rem, temp=0;
	int Number=Decimal_Number;
	int New_Number;
	while(Number>0)
		{
			Number/=10;
			temp=temp+1;
		}
	if (temp==1)
	{
		New_Number=Decimal_Number-3;
	}
	if (temp==2)
	{
		New_Number=Decimal_Number-33;
	}
	if (temp==3)
	{
		New_Number=Decimal_Number-333;	
	}
	if (temp==4)
	{
		New_Number=Decimal_Number-3333;
	}
	if (temp==1)
	{
		New_Number=Decimal_Number-33333;
	}
	if (temp==6)
	{
		New_Number=Decimal_Number-333333;
	}
	return New_Number;
}		
		
	public:
		void display_Option()
		{
			cout<<"1) Decimal Number"<<endl;
			cout<<"2) Binary Number"<<endl;
			cout<<"3) Octal Number"<<endl;
			cout<<"4) Hexadecimal Number"<<endl;
			cout<<"5) Binary Coded Decimal"<<endl;
			cout<<"6) Gray Code "<<endl;
			cout<<"7) Excess-3 Code"<<endl;
		}
		int get_Choice()
		{
			cout<<"Enter which number you want to convert:"<<endl;
			cin>>choice;
			return choice;
			
		}
		void decimal_choice()
		{
		
			
			int Decimal_Number;
			int target;
			cout<<"Enter Decimal Number:"<<endl;
			cin>>Decimal_Number;
			cout<<"In which number you want to convert "<<Decimal_Number<<endl;
			cin>>target;
			if (target==1)
			{
				cout<<"You enter the same number Decimal"<<endl;
				cout<<"Enter other than 1 to convert it into other number"<<endl;
				cout<<endl;
			}
			else if (target==2)
			{
				cout<<"The Binary equivalent of "<<Decimal_Number<<"=";
				Convert_DecimalTo_Binary(Decimal_Number);
				cout<<endl;
				

			}
			else if (target==3)
			{
				cout<<"The Octal equivaleent of "<<Decimal_Number<<"=";
				Convert_DecimalTo_Octal(Decimal_Number);
				cout<<endl;
				
			
			}
			else if (target==4)
			{	
				cout<<"The Hexa Decimal equivalent of "<<Decimal_Number<<"=";
				Convert_DecimalTo_Hexadecimal(Decimal_Number);
				cout<<endl;
				
			
			}
			else if (target==5)
			{
				cout<<"The Binary Coded Decimal equivalent of "<<Decimal_Number<<"=";
				Convert_DecimalTo_BCD(Decimal_Number);
				cout<<endl;
			
				
			}
			else if (target==6)
			{
				cout<<"The GrayCode equivalent of "<<Decimal_Number<<"=";
				Convert_DecimalTo_GrayCode(Decimal_Number);
				cout<<endl;
				
			
				
			}
			else if (target==7)
			{
				cout<<"The Excess-3 Code equivalent of "<<Decimal_Number<<"=";
				Convert_DecimalTo_Excess3Code(Decimal_Number);
				cout<<endl;
			}
		}
		int get_Binary_Number()
		{
			int Binary_Number;
			cout<<"Enter Binary Number:"<<endl;
			cin>>Binary_Number;
			return Binary_Number;
		}
		void Binary_Choice(int Binary_Number)
		{
			int rem, target;
			cout<<"In which number you want to convert: "<<Binary_Number<<endl;
			cin>>target;
			if (target==1)
			{
				
				int Binary_To_Decimal_Number=Convert_Binary_To_Decimal(Binary_Number);
				cout<<"The decimal equivalent of "<<Binary_Number<<"= "<<Binary_To_Decimal_Number;
				
			}
			else if (target==2)
			{
				cout<<"You enter the same number Binary"<<endl;
				cout<<"Enter other than 2 to convert Binary into other number"<<endl;
			}
			else if (target==3)
			{
				int Decimal_Number=Convert_Binary_To_Decimal(Binary_Number);
				cout<<"The octal equivalent of "<<Binary_Number<<"=";
				Convert_DecimalTo_Octal(Decimal_Number);
			
			}
			else if (target==4)
			{
				int Decimal_Number=Convert_Binary_To_Decimal(Binary_Number);
				cout<<"The hexadecimal equivalent of"<<Binary_Number<<"=";
				Convert_DecimalTo_Hexadecimal(Decimal_Number);		
			}
			else if (target==5)
			{
				int Decimal_Number=Convert_Binary_To_Decimal(Binary_Number);
				cout<<"The Binary Coded equivalent of "<<Binary_Number<<"=";
				Convert_DecimalTo_BCD(Decimal_Number);
				
			}
			else if (target==6)
			{
				int Decimal_Number=Convert_Binary_To_Decimal(Binary_Number);
				cout<<"The GrayCode equivalent of "<<Binary_Number<<"=";
				Convert_DecimalTo_GrayCode(Decimal_Number);
			}
			else if(target==7)
			{
				int Decimal_Number=Convert_Binary_To_Decimal(Binary_Number);
				cout<<"The excess-3 code of "<<Binary_Number<<"=";
				Convert_DecimalTo_Excess3Code(Decimal_Number);
			}
	}
	int get_Octal_Number()
	{
			int Octal_Number;
			cout<<"Enter Octal Number:"<<endl;
			cin>>Octal_Number;
			return Octal_Number;
	}
	void Octal_Choice(int Octal_Number)
		{
			int target, rem;
			cout<<"In which number you want to convert "<<Octal_Number<<endl;
			cin>>target;
			int Decimal_Number;
			Decimal_Number=Convert_Octal_To_Decimal(Octal_Number);
			if (target==1)
			{
				cout<<"The Decimal equivalent of "<<Octal_Number<<"="<<Decimal_Number<<endl;
			}
			if (target==2)
			{
				cout<<"The Binary equivalent of "<<Octal_Number<<"=";
				Convert_DecimalTo_Binary(Decimal_Number);
			}
			if (target==3)
			{
				cout<<"You have entered same number. Enter other than 3 to convert "<<Octal_Number<<" into other number"<<endl;
			}
			if (target==4)
			{
				cout<<"The hexadecimall equivalent of "<<Octal_Number<<"=";
				Convert_DecimalTo_Hexadecimal(Decimal_Number);
			}
			if (target==5)
			{
				cout<<"The Binary Coded Decimal equivalent of "<<Octal_Number<<"=";
				Convert_DecimalTo_BCD(Decimal_Number);
			}
			if (target==6)
			{
				cout<<"The Gray Code equivalent of "<<Octal_Number<<"=";
				Convert_DecimalTo_GrayCode(Decimal_Number);
			}
			if (target==7)
			{
				cout<<"The Excess-3 Code equivalent of "<<Octal_Number<<"=";
				Convert_DecimalTo_Excess3Code(Decimal_Number);
				
			}
		}
		string get_HexaDecimal_Number()
		{
			string HexaDecimal_Number;
			cout<<"Enter the Hexadecimal Number:"<<endl;
			cin>>HexaDecimal_Number;
			return HexaDecimal_Number;
		}
		void HexaDecimal_Choice(string HexaDecimal_Number)
			{
				int target;
				cout<<"In which number you want to  convert "<<HexaDecimal_Number<<":"<<endl;
				cin>>target;
				int Decimal_equivalent=Convert_Hexadecimal_To_Decimal(HexaDecimal_Number);
				if (target==1)
				{
					cout<<"The Decimal equivalent of "<<HexaDecimal_Number<<"=";
					cout<<Decimal_equivalent<<endl;
				}
				if(target==2)
				{
					cout<<"The Binary Equivalent of "<<HexaDecimal_Number<<"=";
					Convert_DecimalTo_Binary(Decimal_equivalent);
				}
				if (target==3)
				{
					cout<<"The Octal Equivalent of "<<HexaDecimal_Number<<"=";
					Convert_DecimalTo_Octal(Decimal_equivalent);
					
				}
				if (target==4)
				{
					cout<<"You have entered the same  Hexadecimla Choice. Please other than this to convert "<<HexaDecimal_Number<<" into other number"<<endl;
				}
				if (target==5)
				{
					cout<<"The Binary Coded Decimal equivalent of "<<HexaDecimal_Number<<"=";
					Convert_DecimalTo_BCD(Decimal_equivalent);
				}
				if (target==6)
				{
					cout<<"The Gray Code equivalent of "<<HexaDecimal_Number<<"=";
					Convert_DecimalTo_GrayCode(Decimal_equivalent);
					
				}
				if (target==7)
				{
					cout<<"The Excess-3 equivalent of "<<HexaDecimal_Number<<"=";
					Convert_DecimalTo_Excess3Code(Decimal_equivalent);
				}
			}
			string get_BCD_Code()
			{
				string s;
				cout<<"Enter the Binary Coded Decimal:"<<endl;
				cin>>s;
				return s;
			}
			void Binary_Coded_Decimal_Choice(string BCD_Code)
			{
				int target;
				cout<<"In which number you want to convert "<<BCD_Code<<":"<<endl;
				cin>>target;
				int decimal_equivalent=Convert_BCD_To_Decimal(BCD_Code);
				if (target==1)
				{
					cout<<"The Decimal equivalent of "<<BCD_Code<<"=";
					cout<<decimal_equivalent;
				}
				if (target==2)
				{
					cout<<"The Binary equivalent of "<<BCD_Code<<"=";
					Convert_DecimalTo_Binary(decimal_equivalent);
				}
				if (target==3)
				{
					cout<<"The Octal equivalent of "<<BCD_Code<<"=";
					Convert_DecimalTo_Octal(decimal_equivalent);
				}
				if (target==4)
				{
					cout<<"The Hexadecimal equivalent of"<<BCD_Code<<"=";
					Convert_DecimalTo_Hexadecimal(decimal_equivalent);
				}
				if (target==5)
				{
					cout<<"You have entered the same choice. Please enter other than this to convert "<<BCD_Code<<" into other number"<<endl;
				}
				if (target==6)
				{
					cout<<"The GrayCode equivalent of "<<BCD_Code<<"=";
					Convert_DecimalTo_GrayCode(decimal_equivalent);
				}
				if (target==7)
				{
					cout<<"The Excess-3 code of "<<BCD_Code<<"=";
					Convert_DecimalTo_Excess3Code(decimal_equivalent);
				}
			}
			string get_GrayCode()
			{
				string Gray_Code;
				cout<<"Enter the GrayCode:"<<endl;
				cin>>Gray_Code;
				return Gray_Code;
			}
			void GrayCode_Choice(string Gray_Code)
			{
				int target;
				cout<<"Enter in which you want to convert "<<Gray_Code<<":"<<endl;
				cin>>target;
				int decimal_equivalent=Convert_GrayCodeDecimal(Gray_Code);
				if (target==1)
				{
					cout<<"The decimal equivalent of "<<Gray_Code<<"=";
					cout<<decimal_equivalent;
				}
				if (target==2)
				{
					cout<<"The Binary equivalent of "<<Gray_Code<<"=";
					Convert_DecimalTo_Binary(decimal_equivalent);
				}
				if (target==3)
				{
					cout<<"The Octal equivalent of "<<Gray_Code<<"=";
					Convert_DecimalTo_Octal(decimal_equivalent);
				}
				if (target==4)
				{
					cout<<"The Hexadecimal equivalent of "<<Gray_Code<<"=";
					Convert_DecimalTo_Hexadecimal(decimal_equivalent);
				}
				if  (target==5)
				{
					cout<<"The Binary Coded Decimal equivalent of "<<Gray_Code<<"=";
					Convert_DecimalTo_BCD(decimal_equivalent);
				}
				if (target==6)
				{
					cout<<"You have entered the same choice. Please enter other than this to convert "<<Gray_Code<<" into other number system"<<endl;
				 } 
				if (target==7)
				{
					cout<<"The Excess-3 Code of "<<Gray_Code<<"=";
					Convert_DecimalTo_Excess3Code(decimal_equivalent);
				}
			}
			string get_Excess_3_Code()
			{
				string Excess_3_Code;
				cout<<"Enter Excess-3 Code:"<<endl;
				cin>>Excess_3_Code;
				return Excess_3_Code;
			}
			void Excess_3_Code_Choice( string Excess_3_Code)
			{
				int target;
				cout<<"Enter in which number you want to convert "<<Excess_3_Code<<":"<<endl;
				cin>>target;
				int Decimal_equivalent= Convert_BCD_To_Decimal(Excess_3_Code);
				int Real_Decimal=Convert_Excess_3_Code_to_Decimal(Decimal_equivalent);
				if (Real_Decimal<0)
				Real_Decimal=(-1)*Real_Decimal;
				else
				Real_Decimal=Real_Decimal;
				if (target==1)
				{
					cout<<"The Decimal equivalent of "<<Excess_3_Code<<"=";
					cout<<Real_Decimal;
				}
				if (target==2)
				{
					cout<<"The Binary equivalent of "<<Excess_3_Code<<"=";
					Convert_DecimalTo_Binary(Real_Decimal);
				}
				if (target==3)
				{
					cout<<"The Octal equivalent of "<<Excess_3_Code<<"=";
					Convert_DecimalTo_Octal(Real_Decimal);
				}
				if (target==4)
				{
					cout<<"The Hexadecimal equivalent of "<<Excess_3_Code<<"=";
					Convert_DecimalTo_Hexadecimal(Real_Decimal);
				}
				if (target==5)
				{
					cout<<"The Binary Coded Decimal equivalent of "<<Excess_3_Code<<"=";
					Convert_DecimalTo_BCD(Real_Decimal);
				}
				if (target==6)
				{
					cout<<"The Gray Code equivalent of "<<Excess_3_Code<<"=";
					Convert_DecimalTo_GrayCode(Real_Decimal);
				}
				if (target==7)
				{
					cout<<"You have entered the same number. Please enter other than this to convert "<<Excess_3_Code<<" into other number"<<endl;
				}
				
			}
};
class Coordinate_Converter: public virtual Converter
{
	private:
		int choice;
		void Convert_Rectangular_To_Cylindrical(float x, float y, float z)
	{
		float P, Phi;
		P=sqrt(x*x+y*y);
		Phi=(atan(y/x)*180)/3.142857;
		cout<<"P="<<P<<","<<"Phi="<<Phi<<","<<"z="<<z<<endl;
	}
	void Convert_Rectangular_To_Spherical(float x ,float y, float z)
	{
		float r, Theta, Phi;
		r=sqrt(x*x+y*y+z*z);
		Theta=(acos(z/r)*180)/3.142857;
		Phi=(atan(y/x)*180)/3.142857;
		cout<<"r="<<r<<","<<"Theta="<<Theta<<","<<"Phi="<<Phi<<endl;
	}
	void Convert_Cylindrical_To_Rectangular(float p, float phi, float z)
	{
		float x,y, Radian_Phi;
		Radian_Phi=(3.142857*phi)/180;
		x=p*cos(Radian_Phi);
		y=p*sin(Radian_Phi);
		cout<<"x="<<x<<"y="<<y<<"z="<<z;
	}	
	void Convert_Cylindrical_To_Spherical(float p, float phi, float z)
	{
		float x,y, Radian_Phi;
		Radian_Phi=(3.142857*phi)/180;
		x=p*cos(Radian_Phi);
		y=p*sin(Radian_Phi);
		float r, Theta, Phi;
		r=sqrt(x*x+y*y+z*z);
		Theta=(acos(z/r)*180)/3.142857;
		Phi=(atan(y/x)*180)/3.142857;
		cout<<"r="<<r<<","<<"Theta="<<Theta<<","<<"Phi="<<Phi<<endl;
	}

	void Convert_Spherical_To_Rectangular(float r, float theta, float phi)
	{
		float R, x,y;
		float Radian_Phi, Radian_Theta;
		R=sqrt(x*x+y*y);
		Radian_Phi=(3.142857*phi)/180;
		x=R*cos(Radian_Phi);
		y=R*sin(Radian_Phi);
		Radian_Theta=(3.142857*theta)/180;
		float z=(cos(Radian_Theta))*r;
		cout<<"x="<<x<<"y="<<y<<"z="<<z;
	}
	void Convert_Spherical_To_Cylindrical(float r, float theta, float phi)
	{
		float R, x,y;
		float Radian_Phi, Radian_Theta;
		R=sqrt(x*x+y*y);
		Radian_Phi=(3.142857*phi)/180;
		x=R*cos(Radian_Phi);
		y=R*sin(Radian_Phi);
		Radian_Theta=(3.142857*theta)/180;
		float z=(cos(Radian_Theta))*r;
		float P;
		P=sqrt(x*x+y*y);
		phi=(atan(y/x)*180)/3.142857;
		cout<<"P="<<P<<","<<"Phi="<<phi<<","<<"z="<<z<<endl;
		}
	public:
		void display_Option()
		{
			cout<<"1) Rectagular Coordinate System"<<endl;
			cout<<"2) Cylindrical Coordinate System"<<endl;
			cout<<"3) Spherical Coordinate System"<<endl;
		}
		int get_Choice()
		{
			int Convert_Choice;
			cout<<"Enter the which Coordinate system you want to convert:"<<endl;
			cin>>Convert_Choice;
			return Convert_Choice;
		}
		void Rectangula_Choice()
		{
			float x,y,z;
			cout<<"Enter the rectangular coordinate:"<<endl;
			cout<<"x=";
			cin>>x;
			cout<<"y=";
			cin>>y;
			cout<<"z=";
			cin>>z;
			int target;
			cout<<"In which Coordinate System you want to convert "<<"x="<<x<<",y="<<y<<",z="<<z<<endl;
			cin>>target;
			if (target==1)
			{
				cout<<"You have entered the same choice. please enter other than this to convert your Rectagular to oany other coordinate system"<<endl;
			}
			if (target==2)
			{
				cout<<"The Cylindrical Coordinate of "<<"x="<<x<<",y="<<y<<",z="<<z<<" is: ";
				Convert_Rectangular_To_Cylindrical(x, y,z);
			}
			if (target==3)
			{
				cout<<"The Spherical Coordinate of"<<"x="<<x<<",y="<<y<<",z="<<z<<" is: ";
				Convert_Rectangular_To_Spherical(x,y,z);
			}
		}
		void Cylindrical_Choice()
		{
			float p, Phi,z;
			cout<<"Enter the Cylindrical Coordinate:"<<endl;
			cout<<"p=";
			cin>>p;
			cout<<"Phi=";
			cin>>Phi;
			cout<<"z";
			cin>>z;
			int target;
			cout<<"In which Coordinate system you want to convert"<<"p="<<p<<".Phi="<<Phi<<",z="<<z<<endl;
			cin>>target;
			if (target==1)
			{
				cout<<"The Rectangular Coordinate of "<<"p="<<p<<",Phi="<<Phi<<",z="<<z<<" is:";
				Convert_Cylindrical_To_Rectangular(p, Phi, z);
			}
			if (target==2)
			{
				cout<<"You have entered the same choice. Please enter ohter than this to convert Cylindrical from othee coordinate system"<<endl;
			}
			if (target==3)
			{
				cout<<"The Spherical Coordinate of "<<"p="<<p<<"Phi="<<Phi<<",z="<<z<<" is:";
				Convert_Cylindrical_To_Spherical(p, Phi, z);
			}
		}
		void Spherical_Choice()
		{
			float r,Theta, Phi;
			cout<<"Enter the spherical Coordinate:"<<endl;
			cout<<"r=";
			cin>>r;
			cout<<"Theta=";
			cin>>Theta;
			cout<<"Phi=";
			cin>>Phi;
			int target;
			cout<<"In which Coordinate system you want to  convert "<<"r="<<r<<",Teta="<<Theta<<",Phi="<<Phi<<endl;
			cin>>target;
			if  (target==1)
			{
				cout<<"The Rectangular Coordinate of "<<"r="<<r<<",Theata="<<Theta<<",Phi="<<Phi<<" is:";
				Convert_Spherical_To_Rectangular( r,Theta,  Phi);
			}
			if (target==2)
			{
				cout<<"The Cylindrical Coordinate of "<<"r="<<r<<",Theta="<<Phi<<",Phi="<<Phi<<" is:";
				Convert_Spherical_To_Cylindrical(r, Theta, Phi);
			}
			if (target==3)
			{
				cout<<"You have entered the same Coordinate system. Please enter other than this to convert Spherical Coordinate to other coordinate"<<endl;
			}
		}
};
int main()
{
	system("color 0A");
	cout<<"                                              **||||||| CONVERTER |||||||**"<<endl;
	cout<<"\n \n \n"<<endl;
	cout<<"Prepared By:\nAmrit Thapa (076EL006)"<<endl;
	cout<<"Adarsha Chalise (076BEL00)"<<endl;
	cout<<"Brijkishore Pandit (076BEL0)"<<endl;
	cout<<"Ishwor Shrestha (076BEL0)"<<endl;
	char c;
	cout<<"Enter any key to continue"<<endl;
	cin>>c;
	system("cls");
	while (c)
	{
		Converter c1;
		c1.show_content();
		break;
	}
	while(1)
	{
	cout<<"Enter your choice:"<<endl;
	cout<<"Enter 1 for Number Converter."<<endl;
	cout<<"Enter 2 for coordinate Converter."<<endl;
	int choice;
	cin>>choice;
	system("cls");
	int Convert_Choice;
	int Coordinate_Convert_Choice;
	if (choice ==1)
	{
		cout<<"                              Here you can convert Numbers."<<endl;
		Digital_Converter DC;
		DC.display_Option();
		Convert_Choice=DC.get_Choice();
		if (Convert_Choice==1)
		{
			DC.decimal_choice();
		}
		if (Convert_Choice==2)
		{
			int Binary_Number=DC.get_Binary_Number();
			int Check_Binary_Number=Binary_Number;
			int rem;
		while (Check_Binary_Number>0)
			{
				rem=Check_Binary_Number%10;
				if (rem>1)
				{
					cout<<"Invalid Binary Number. You should Enter number  only 1 and 0."<<endl;
					Check_Binary_Number/=10;
					break;
				}
				//Check_Binary_Number/=10;
				else
				
				{
				DC.Binary_Choice(Binary_Number);
				break;
			}
			}
	}
		if (Convert_Choice==3)
		{
					
			int Octal_Number=DC.get_Octal_Number();
			int Check_Octal_Number=Octal_Number;
			int rem;
			while (Check_Octal_Number>0)
			{
				rem=Check_Octal_Number%10;
				if (rem>7)
				{
					cout<<"Invalid Octal Number. You should Enter number  between 0 and 7."<<endl;
					Check_Octal_Number/=10;
					break;
				}
				else
				{
						DC.Octal_Choice(Octal_Number);
						break;
				}
			}
		}
		if (Convert_Choice==4)
		{
		string HexaDecimal_Number=DC.get_HexaDecimal_Number();
		int n = HexaDecimal_Number.length();
    	for(int i = 0; i < n; i++)
    	{
    	char  ch = HexaDecimal_Number[i];
        if ((ch < '0' || ch > '9') && (ch < 'A' || ch > 'F'))
        {
            cout <<"Invalid Hexadecimla Number. Please Check your Hexadecimal Number" << endl;
        }
    	}
        DC.HexaDecimal_Choice(HexaDecimal_Number);
        }
        if (Convert_Choice==5)
        {
        	string BCD_Code;
        	BCD_Code=DC.get_BCD_Code();
        	stringstream geek(BCD_Code);
        	int Check_BCD;
        	geek>>Check_BCD;
        	int rem;
        	while (Check_BCD>0)
			{
				rem=Check_BCD%10;
				if (rem>1)
				{
					cout<<"Invalid Binary Coded Decimal Number. You should Enter number only 1 and 0."<<endl;
					Check_BCD/=10;
					break;
				}
				else
				{
					DC.Binary_Coded_Decimal_Choice(BCD_Code);
					break;
				}
			}
		}
		if (Convert_Choice==6)
		{
			string Gray_Code;
        	Gray_Code=DC.get_GrayCode();
        	stringstream geek(Gray_Code);
        	int Check_Gray;
        	geek>>Check_Gray;
        	int rem;
        	while (Check_Gray>0)
        	{
        		rem=Check_Gray%10;
				if (rem>1)
				{
					cout<<"Invalid Binary Coded Decimal Number. You should Enter number only 1 and 0."<<endl;
					Check_Gray/=10;
					break;
				}
				else
				{
					DC.GrayCode_Choice(Gray_Code);
					break;
				}
        	}
	}
	if (Convert_Choice==7)
	{
		string Excess_3_Code=DC.get_Excess_3_Code();
        stringstream geek(Excess_3_Code);
        int Check_Excess_3;
        geek>>Check_Excess_3;
        int rem;
        while (Check_Excess_3>0)
        {
        	rem=Check_Excess_3%10;
			if (rem>1)
			{
				cout<<"Invalid Binary Coded Decimal Number. You should Enter number only 1 and 0."<<endl;
				Check_Excess_3/=10;
				break;
			}
			else
			{
				DC.Excess_3_Code_Choice(Excess_3_Code);
				break;
			}
		}
    }
}
	else if(choice==2)
	{
		cout<<"                              Here you can convert Coordinate."<<endl;
		Coordinate_Converter CC;
		CC.display_Option();
		Coordinate_Convert_Choice=CC.get_Choice();
		if (Coordinate_Convert_Choice==1)
		{
			CC.Rectangula_Choice();
		}
		if (Coordinate_Convert_Choice==2)
		{
			CC.Cylindrical_Choice();
		}
		if (Coordinate_Convert_Choice==3)
		{
			CC.Spherical_Choice();
		}
	}
	cout<<endl;
	char Character;
	if (Character)
	{
	system("cls");
	}

}
}


