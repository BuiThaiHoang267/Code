using System;
using System.Collections.Specialized;

namespace Fraction
{
    class Program
    {
        public class Fraction
        {
            private int numerator;
            private int denominator;

            public Fraction()// ham tao mac dinh
            {
                numerator = 0; denominator = 1;
            }

            public int Numerator // get set tu so
            {
                get
                {
                    return numerator;
                }
                set
                {
                    numerator = value;
                }
            }
            public int Denominator // get set mau so
            {
                get 
                { 
                    return denominator;
                }
                set 
                { 
                    if(value != 0 ) 
                    {
                        denominator = value;
                    }
                }
            }
            public void Input()
            {
                Console.Write("Numerator: ");
                numerator = int.Parse( Console.ReadLine() );
                Console.Write("Denominator: ");
                denominator = int.Parse( Console.ReadLine() ) ;
            }
            public void Output() 
            {
                Console.WriteLine($"{numerator}/{denominator}");
            }
            public Fraction add( Fraction another )
            {
                Fraction temp = new Fraction(); 
                temp.numerator = numerator*another.denominator + denominator*another.numerator; 
                temp.denominator = denominator*another.denominator;
                temp.Compact();
                return temp;
            }
            public Fraction sub(Fraction another)
            {
                Fraction temp = new Fraction();
                temp.numerator = numerator * another.denominator - denominator * another.numerator;
                temp.denominator = denominator * another.denominator;
                temp.Compact();
                return temp;
            }
            public Fraction mul(Fraction another)
            {
                Fraction temp = new Fraction();
                temp.numerator = numerator * another.numerator;
                temp.denominator = denominator * another.denominator;
                temp.Compact();
                return temp;
            }
            public Fraction div(Fraction another)
            {
                Fraction temp = new Fraction();
                temp.numerator = numerator * another.denominator;
                temp.denominator = denominator * another.numerator;
                temp.Compact();
                return temp;
            }
            public Fraction Compact()
            {
                int a = Math.Abs(numerator);
                int b = Math.Abs(denominator);
                if(a == 0)
                {
                    return this;
                }

                while (a != b )
                {
                    if (a > b)
                        a = a - b;
                    else
                        b = b - a;
                }
                numerator = numerator / a;
                denominator = denominator / a;
                return this;
            }
        }
        public static void Main()
        {
            Fraction A = new Fraction();
            Fraction B = new Fraction();
            Fraction C = new Fraction();
            A.Input();
            B.Input();
            C = A.add(B);
            C.Output();
            C = A.sub(B);
            C.Output();
            C = A.mul(B);
            C.Output();
            C = A.div(B);
            C.Output();
        }

    }
}

