using System;
using System.Linq;

namespace MyCompiler {
    class Program {
        public static void Main(string[] args) {
            var totalPrice = Int32.Parse(Console.ReadLine());
            var count = Int32.Parse(Console.ReadLine());

            var sumPrice = 0;
            for(var i = 0; i < count ; i++) 
            {
                var input = Console.ReadLine().Split(" ").Select(x => Int32.Parse(x));
                sumPrice += input.ElementAt(0) * input.ElementAt(1);
            }

            Console.WriteLine(sumPrice == totalPrice ? "Yes" : "No");
        }
    }
}