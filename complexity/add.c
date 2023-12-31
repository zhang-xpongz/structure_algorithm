
// 全局变量，大小为10的数组array，长度len，下标i。
int array[] = new int[10]; 
int len = 10;
int i = 0;

// 往数组中添加一个元素
void add(int element) {
   if (i >= len) { // 数组空间不够了
     // 重新申请一个2倍大小的数组空间
     int new_array[] = new int[len*2];
     // 把原来array数组中的数据依次copy到new_array
     for (int j = 0; j < len; ++j) {
       new_array[j] = array[j];
     }
     // new_array复制给array，array现在大小就是2倍len了
     array = new_array;
     len = 2 * len;
   }
   // 将element放到下标为i的位置，下标i加一
   array[i] = element;
   ++i;
}

最好时间复杂度：本次插入时数组中有空间，则直接插入，此时时间复杂度）O(1)
最坏时间复杂度：本次插入时数组中没有空间，则需要重新申请2倍大小空间，遍历，原先数组赋值后在插入，此时时间复杂度O(n)
均摊时间复杂度: O(1)
平均时间复杂度: O(1)

