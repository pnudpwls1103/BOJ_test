using System;
using System.Linq;
using System.Collections.Generic;

namespace MyCompiler {
    class Program {
        public static void Main(string[] args) {
            var input = Console.ReadLine().Split(" ").Select(x => Int32.Parse(x));
            var n = input.ElementAt(0);
            var m = input.ElementAt(1);

            var result = new int[n+1];
            var rows = new IEnumerable<int>[m];
            for (int i = 0; i < m; i++) {
                rows[i] = Console.ReadLine().Split(" ").Select(x => Int32.Parse(x));
            }

            for (int i = rows.Count() - 1; i >= 0; i--) {
                var row = rows[i];
                var start = row.ElementAt(0);
                var end = row.ElementAt(1);
                var num = row.ElementAt(2);
                for (int j = start; j <= end; j++) {
                    if (result[j] > 0) continue;
                    result[j] = num;
                }
            }

            for(int i = 1; i <= n; i++)
                Console.Write(result[i] + " ");
        }
    }
}