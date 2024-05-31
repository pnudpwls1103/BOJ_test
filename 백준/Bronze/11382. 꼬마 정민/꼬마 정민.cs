using System;
using System.Linq;

namespace MyCompiler {
    class Program {
        public static void Main(string[] args) {
            var input = Console.ReadLine();
            var nums = input.Split(' ').Select((n) => Int64.Parse(n));
            Console.WriteLine(nums.Sum());
        }
    }
}