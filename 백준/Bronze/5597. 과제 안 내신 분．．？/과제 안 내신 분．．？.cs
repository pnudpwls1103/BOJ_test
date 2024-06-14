using System;

namespace MyCompiler {
    class Program {
        public static void Main(string[] args) {
            var num = new bool[31];

            for (var i = 0; i < 28; i++) {
                var n = Console.ReadLine();
                num[Convert.ToInt32(n)] = true;
            }

            for (var i = 1; i <= 30; i++) {
                if (!num[i]) Console.WriteLine(i);
            }
        }
    }
}