using System;
using System.Linq;

namespace MyCompiler {
    class Program {
        public static void Main(string[] args) {
            var input = Console.ReadLine().Split(" ").Select(x => Convert.ToInt32(x));
            var n = input.ElementAt(0);
            var m = input.ElementAt(1);
            var num = new int[n];
            for(var i = 0; i < n; i++)
            {
                num[i] = i+1;    
            }

            var temp = 0;
            for (var k = 0; k < m; k++)
            {
                input = Console.ReadLine().Split(" ").Select(x => Convert.ToInt32(x));
                var i = input.ElementAt(0) - 1;
                var j = input.ElementAt(1) - 1;
                temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }

            foreach (var ni in num)
            {
                Console.Write(ni + " ");
            }
        }
    }
}