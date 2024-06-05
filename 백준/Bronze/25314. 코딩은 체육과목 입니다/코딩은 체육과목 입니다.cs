using System;

namespace MyCompiler {
    class Program {
        public static void Main(string[] args) {
            var bytes = Int32.Parse(Console.ReadLine());
            var total = bytes / 4;
            for(var i = 0; i < total; i++)
                Console.Write("long ");
            Console.Write("int");
        }
    }
}