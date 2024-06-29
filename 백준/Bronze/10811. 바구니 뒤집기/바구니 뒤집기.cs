using System;
using System.Linq;
using System.Collections.Generic;

namespace MyCompiler {
    class Program {
        public static void Main(string[] args) {
            var input = Console.ReadLine().Split(' ').Select(x => Convert.ToInt32(x));
            var n = input.ElementAt(0);
            var m = input.ElementAt(1);

            var nums = new List<int>();
            for (var i = 0; i <= n; i++) {
                nums.Add(i);
            }
            
            for (var i = 0; i < m; i++) {
                input = Console.ReadLine().Split(' ').Select(x => Convert.ToInt32(x));
                var ii = input.ElementAt(0);
                var ij = input.ElementAt(1);
                var count = (ij - ii) / 2;

                for (var j = 0; j <= count; j++) {
                    var temp = nums[ij - j];
                    nums[ij - j] = nums[ii + j];
                    nums[ii + j] = temp;
                }
            }

            for(var i = 1; i <= n; i++) {
                Console.Write(nums[i] + " ");
            }
        }
    }
}