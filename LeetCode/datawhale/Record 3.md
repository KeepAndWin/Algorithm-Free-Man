### ð������

һ�ֻ��ڽ���������
**������**��ֻ��һ�ˣ�δ���ֽ���Ԫ�ء�O��n��
**һ�����**��O��n^2��
**�ȶ���**���ȶ��ģ���ȵ�Ԫ�ز��ᱻ����\*\*��\*\*

### ѡ������

ÿ�δ����򲿷���ѡ����Сһ����~~���� idx ����~~ �� idx ����Ԫ�ؽ���λ�ã�����ܻ����Ԫ�����λ�õı仯��ָ����ԭ�� idx ����Ԫ��������ȵ�Ԫ�أ���
**����**��������������������Ĵ�������һ���ġ����� O��n^2��
**�ȶ���**�����ȶ��ġ�

### ��������

�����򲿷��еĵ�һ��Ԫ�أ����뵽ǰ�����򲿷��е���ȷλ���ϡ�����Ĳ��������Ĳ�������һ�£��漰���ƶ�Ԫ�ء�
\*\*��������\*\*ÿ�ζ�����Ҫ���룬��ζ�Ų����ƶ�Ԫ�� O(n)
**����**������O��n^2��
**�ȶ���**���ȶ������Ԫ�ص����λ�ò���ı䣬�����ⲻ��һ�����ڽ������㷨����λֱ�ӽ�������Ԫ��λ�ã�������һ�����ȶ��ġ�

### ��ϰ��Ŀ���� 05 �죩

#### 1.��ָ Offer 45. �������ų���С����

#### 1.1 ��Ŀ����

**������** ����һ���Ǹ��������� ��

Ҫ�󣺽������е�����ƴ�������ų�һ��������ӡ��ƴ�ӳ������������е���С��һ����

#### M��

����С�����������飬С����˼�����λС�ĲŽ�С��
������λ��ͬ�ͱȽϴθ�λ���������ơ����λ��������ֱ���~~ǰһλ�Ľ��~~������ 3 �� 34�����ڣ�ֻ��һλ�����λ��ͬ���Ƚϵڶ�λ��ʱ��ֱ���ã������������ɣ��������ɾ��ǣ��������ǵ�ƴ�ӹ��� �����ڣ�֮����������λ�϶��ǲ�С�ڣ��ġ�
�ǰһλ������λ���ǲ����Ʒ���������������������
����\[82,827] \[12,121],��򵥵�������������ʵʵƴ���������� ��С�ɡ�

#### C��

���������˼·����һ���ȽϺ���������Ч�����У�����λ������ʱ�������⣬���� 0 Ӧ����������Ϊ 1����ʹ�� Math API ʱ�ⲻ�ô���

```java
 public static boolean compare(int a, int b){
        // a < b ����true�� ���򷵻�false

        // �������ֱȴ�С���ȱȽ����λ��
        int a_l = (int) Math.log10(a)+1; // a�ĳ���
        int b_l = (int) Math.log10(b)+1; // b�ĳ���
        int a_ = a / (int)Math.pow(10, a_l - 1); // a�����λ
        int b_ = b / (int)Math.pow(10, b_l - 1); // b�����λ
        int top_a = a_;
        int top_b = b_;
        while(a_l > 0 || b_l > 0){
            if(a_ < b_){ // ���λ��ֱ���жϳ���С��ϵ
                return true;
            }
            if(b_ < a_){// ���λ��ֱ���жϳ���С��ϵ
                return false;
            }
            a_l--;b_l--;
            if(a_l <= 0){
                a_ = top_a;
            }else{
                a_ = (a / (int)Math.pow(10, a_l - 1)) % 10;
            }
            if(b_l <= 0){
                b_ top_b;
            }else{
                b_ = (b / (int)Math.pow(10, b_l - 1)) % 10;
            }
        }
        return false;  // a��û�б�bС
    }

```

��������⣬ѧϰ��һ�ָ��õıȽϷ�����ab ƴ�ɵ����������С�� ba ƴ�ɵ�����˵�� a ��С�����ʺ���ǰ��~~������ַ���ת���� int �о�Ч�ʻ����ǵ���λ��������͡�~~
��ʵֻ��Ҫ ab ba �ַ����Ƚϴ�С���ɣ�

```java
class Solution {
    public String minNumber(int[] nums) {
        // ʹ�ò�������ÿ��ѡ����С��һ������idx����
        for(int i = 0; i < nums.length; i++){
            int min = i;
            for(int j = i + 1; j < nums.length; j++){
                if(compare(nums[j], nums[min])){ // j��С�Ļ�
                    min = j;
                }
            }
            // ����λ��
            int temp = nums[i];
            nums[i] = nums[min];
            nums[min] = temp;
        }
        StringBuffer res = new StringBuffer();
        for(int i = 0; i < nums.length; i++){
            res.append(nums[i]);
        }
        return res.toString();


    }
    public boolean compare(int a, int b){
        // ����  a < b �Ľ��
        // ֱ��ʹ���ַ����ıȽϷ�ʽ
        String as = String.valueOf(a);
        String bs = String.valueOf(b);
        String ab = as + bs;
        String ba = bs + as;

        return ab.compareTo(ba) < 0;  // ֱ��ʹ���ַ����ıȽϷ�ʽ

    }

}
```

��Ȼͨ���ˣ�����ִ��Ч�ʲ���

![1713805826123](image/Record3/1713805826123.png)
ѧϰһ�±��˵��ŵ�
�Ż��ķ����ǣ�ֱ�ӽ�ԭ����ת���ַ������飬ֱ��ʹ�� API ��������������� compare ������ʹ������д���ģ����Ǵ�ʱ����Ҫ����ֵת��������ʹ�� lambda ���ʽ��

```java
class Solution {
    public String minNumber(int[] nums) {
        // ʹ�ò�������ÿ��ѡ����С��һ������idx����
        String[] strs = new String[nums.length];
        for(int i = 0; i < nums.length; i++){
            strs[i] = String.valueOf(nums[i]);
        }
        Arrays.sort(strs, (a, b) -> (a + b).compareTo(b + a));
        StringBuilder res = new StringBuilder();
        for(String s : strs){
            res.append(s);
        }
        return res.toString();
    }
}
```

![1713806049554](image/Record3/1713806049554.png)
Ч��������

#### 2.0283. �ƶ���

#### 2.1 ��Ŀ����

**������** ����һ������ ��

**Ҫ��** �������ƶ���ĩβ��������ԭ�еķ����ֵ����˳��

#### M��

��ʵ�����һ��ȥ�ص����⣬����ȥ�� 0��ʹ��ȥ�ص�������˫ָ�룬һ��һ������ָ����ʣ���ָ��ָ����д��λ������ 0 ��ָ���������������ָ������µĿ�λ���� 0 ���ɡ�

#### C��

```java
class Solution {
    public void moveZeroes(int[] nums) {
        int low = 0; // ��ָ��:�洢��λ��
        int high = 0; //��ָ�룺���ʵ�λ��
        for(; high < nums.length; high++){
            if(nums[high] != 0){
                nums[low] = nums[high];
                low++;
            }
        }
        for(;low <nums.length; low++){
            //ʣ�ಿ�����0
            nums[low] = 0;
        }
    }
}
```

![1713805679338](image/Record3/1713805679338.png)

#### 3.0912. ��������

#### 3.1 ��Ŀ����

**������** ����һ���������� ��

**Ҫ��** ���������������С�

#### M��

��Ŀ�е����鳤������� 5W�����ʹ�ÿ���һ��������㷨������ֱ��ʹ�� API �ˡ�

#### C��

```java
class Solution {
    public int[] sortArray(int[] nums) {
        Arrays.sort(nums);
        return nums;
    }
}
```

![1713805656268](image/Record3/1713805656268.png)

### �鲢����

��ǰѧϰ�鲢һֱû����Ĳ��֣�

- �鲢ǰ��һ���ֽ�Ĺ��̣�����ֳ������������֣�**ֱ������Ϊ 1 ����������**
- �ڶ����ֲ��ǣ���������������ϲ���һ������������顣

���ڱ��벿�֣����Ǹ��ݹ���㷨��ֱ�ӿ��Ų�����������ʵ��������ֵݹ�Ĵ������ôд����Щ�����ڵݹ顣��Ϊ���岿����

```java
public int[] mergeSort(int[] nums){
    if(nums.length == 1) // ����Ϊ1��������
        return nums;
    int mid = nums.length / 2;
    left = mergeSort(~~Arrays.copyOfRage(nums, 0, mid)~~);  // �ݹ����� �󲿷�
    right = mergeSort(~~Arrays.copyOfRange(nums, mid, nums.length)~~; // �ݹ����� �Ҳ���
    return merge(left, right); // ���������������ϲ���һ������������顣

    // ʵ�����������Ƶ�����������Ǻ����ױ�ջ�ġ�
}
```

����ѧϰ��ʱ�򣬷ֽ�ͺϲ��Ƿֿ����ģ������еݹ��ԡ���д�ɴ����ʱ���Ҹо�����������һ���ˡ���Ҫ˵�����˵������������ʵÿ���ؼ��㶼�ж�Ӧ�����Ҵ�����Ư���������Ҿ��Ǻ�����Ƴ������Ĵ���ṹ��������������������

ʱ�临�Ӷȣ��鲢�������� O��log��������ÿ�����е�Ԫ�ض��ᱻ����һ�Ρ����������� O��nlog��
�ռ临�Ӷȣ�ÿ�˶�Ҫһ������Ϊ n ������źϲ�֮��Ľ������һ�˵ľͲ������ˡ����Կռ临�� O��n��
�ȶ��ԣ���ʵ�ȶ�����ȫ���Կ���û���漰��Ԫ�صĽ���λ�ã���������㷨������û����ԭ��������λ�ý����Ĳ������Ͼ��ռ临�Ӷ�Ϊ O��n������ �����϶����ȶ��ľ����ˡ�ʵ�������Ԫ�صķֽ⡢�鲢�Ĺ�����λ��Ҳȷʵû�з����ı䡣

### ϣ������

��������ı��� gap ������С�����Ϊ 1�������һ���൱��һ�α�׼�Ĳ������򣩣����������������������һ�˻����ϲ��漰Ԫ��λ�õ��ƶ���

�漰������Ͳ����������ϣ����뻹���ǲ���д��
�����ؼ��㣺���� = �ƶ��Ĳ��� = gap
ϣ��������ƽ�������е㲻ͬ��λ�������ڵ�Ԫ�����ڲ�ͬ���顣
ƽ�����Ƿ� 2 ���� aaaaabbbbb
��ϣ����� 2 ���� ababababab

```java
public class ShellSort {
    public static void main(String[] args){
        int[] nums = {7, 2, 6, 8, 0, 4, 1, 5, 9, 3};
        System.out.println(Arrays.toString(shellSort(nums)));
    }
    public static int[] shellSort(int[] nums){
        // 1. ÿ��ֻ��2��Ԫ�أ������϶ࡣ ���� = ���� = gap
        int gap = nums.length / 2;
        // 2.
        while(gap > 0){
            // ����������ÿ��ĵ�һ��Ԫ�ض�������ġ���ÿ��ĵڶ���Ԫ�ؿ�ʼ
            for(int i = gap; i < nums.length; i++){  // �����˶�ÿ����һ�β�������
                // 2.1 ���������¼��ǰλ��
                int temp = nums[i];
                // 2.2 �ҵ���ǰԪ�ظò����λ�á�������ǰ��ģ��������Ԫ����Ҫ���ơ�
                int j = i;
                while(j >= gap && nums[j - gap] > temp){
                    nums[j] = nums[j - gap];
                    j -= gap;
                }
                nums[j] = temp;
            }
            // ��С���
            gap /= 2;
        }
        return nums;
    }
}
```

����д�������©�������Ժ�Ҫ��ʱ��ʱĬдһ��ϣ�����롣

### ��ϰ��Ŀ���� 06 �죩

#### 1.0506. �������

#### 1.1 ��Ŀ����

**������** ����һ������Ϊ ������ �����б�ʾ�����˶�Ա�ڱ����еĳɼ������гɼ�������ͬ��

**Ҫ��** �ҳ����ǵ�������Σ�������ǰ������Ӧ�Ľ��ơ�ǰ�����˶�Ա���ᱻ�ֱ����衸���ƣ�"Gold Medal"�����������ƣ�"Silver Medal"�����͡�ͭ�ƣ�"Bronze Medal"������

#### M��

����Ĺؼ������ڣ�������֮ǰҪ������ԭ����λ�á������ʹ���ֵ�ӳ�䣬����Ľⷨ�������ڷ�װ����ԭ���ķ�����λ�÷�װ��һ������Ϊ��������������ʱ���Ƕ� �����������Arrays.sort �Զ������򷽷���

#### C��

```java
class Solution {
    public String[] findRelativeRanks(int[] score) {
        int[][] copy = new int[score.length][2];
        String[] strs = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        String[] res = new String[score.length];
        for(int i = 0; i < score.length; i++){
            copy[i][0] = score[i];   // ��һ��λ�÷ŵ÷�
            copy[i][1] = i;         // �ڶ���λ�÷�ԭ��������
        }
        Arrays.sort(copy, (a, b) -> b[0] - a[0]);
        for(int i = 0; i < copy.length; i++){
            if(i < 3){
                res[copy[i][1]] = strs[i];
            }else {
                res[copy[i][1]] = String.valueOf(i + 1);
            }
        }
        return res;
    }
}
```

![1713805628508](image/Record3/1713805628508.png)

#### 2.0088. �ϲ�������������

#### 2.1 ��Ŀ����

**������** ���������������� ����

**Ҫ��** �� �ϲ��� �У�ʹ ��Ϊһ���������顣

#### M��

���������֮�����ڣ�1 ������������Ҫ����ģ�������ǰ m ��λ����ռס�ˣ������ԭ���Ĺ鲢�ϲ���ʽ��̫���á���Ҫ�任һ��˼·���ٴ�С����鲢�����ǴӴ�С�鲢��ָ��ָ���������һ��Ԫ�أ��Ӻ���ǰ�鲢��

#### C��

�����ʣ��ε�ʱ������� nums2 û��գ��ǾͰ���ԭ������������ʣ��ķ��� nums1 ���µĿռ䡣����Ͳ����ٴ����ˡ���Ϊʣ�²���ԭ����λ�� nums1

```java
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int i1 = m - 1;
        int i2 = n - 1;
        int i = m + n - 1;
        while(i1 >=0  && i2 >= 0){
            if(nums1[i1] > nums2[i2]){ // �Ӻ���ǰ�鲢��ÿ������������
                nums1[i--] = nums1[i1--];
            }else{
                nums1[i--] = nums2[i2--];
            }
        }
        if(i2 >= 0){
            while (i2 >= 0){
                nums1[i--] = nums2[i2--];
            }
        }else {
            // ��������λ��nums1�����ù���
        }
    }
}
```

![1713805593203](image/Record3/1713805593203.png)

#### 3.��ָ Offer 51. �����е������

#### 3.1 ��Ŀ����

**������** ����һ������ ��

**Ҫ��** ����������е�����Ե�������

#### M��

����������Ǿ���Ĺ鲢����

������������ A,B �ںϲ��Ľ����У�����������������λ��Ϊ A ��ǰ B �ں󣬼� arr = AB.

��������Եķ����У����ӽ��ǵ�ǰԪ�أ�����ǰԪ���ܺ���֮ǰ����ЩԪ���γ�����ԡ�

�� merge AB ������Ĺ����У��� B��j���е�Ԫ��С�� A��i������ô B��j�����Ժ� A��i\~end����ЩԪ�ض����������ԣ���Ϊ A ������ģ���ЩԪ�ض��� B��j��Ҫ��

��� AB �鲢���γ�һ����Σ��ǳ� C����ʱ C �в���������ԣ�������Ҫ������Ե���λ�� C �Ҳ�� D���ظ��ղ�����Ĳ�����
�������̵�ʵ�֣�Ҳ�����ڹ鲢����� merge �׶����һ�¼�������ԵĴ�����ѡ�����Ĵ����ܺ͹鲢��һ���ġ�

#### C��

```java
class Solution {
    private int count = 0;

    public int[] mergeSort(int[] nums){
        if(nums.length == 1){
            return nums;
        }

        int mid = nums.length / 2;
        int[] left = mergeSort(Arrays.copyOfRange(nums, 0, mid));
        int[] right = mergeSort(Arrays.copyOfRange(nums, mid, nums.length));
        return merge(left, right);
    }

```

~~��������ڵݹ�Ĳ���ʹ�� `Arrays.copyOfRange`�������飬�ᵼ��ջ��������⡣���潫�����޸ĳ����±����ʽ���Σ����ٸ������顣~~

==����һ�£���ʵ�����������====`[]`====�յ����飬�ڵݹ�Ľ����������Ӧ��д�� ====`<= 1`==== ������====` == 1`==
��������д��һ��û�� `Arrays`API �Ĵ���󣬻��ǳ�ͬ��������ϸ�Ķ���һ�²ŷ��ֵġ�

```java
class Solution {
    private int count = 0;
    public int reversePairs(int[] nums) {
        mergeSort(nums, 0, nums.length);
        return count;
    }
    public void mergeSort(int[] nums, int start, int end){
        if(end - start <= 1){ // ���д�� ==1��������������ͻ��������޵ݹ�
            return ;
        }
        int mid = start + (end - start) / 2;
        mergeSort(nums, start, mid);
        mergeSort(nums, mid, end);
        merge(nums, start, mid, end);
    }
    public  void merge(int[] nums, int start, int mid, int end){
        int[] res = new int[end - start];
        int left = start;
        int right = mid;
        int i = 0;
        while(left < mid && right < end){
            if(nums[right] < nums[left]){
                count += mid - left;
                res[i++] = nums[right++];
            }else{
                res[i++] = nums[left++];
            }
        }
        if(right < end){
            while(i < res.length){
                res[i++] = nums[right++];
            }
        }else {
            while(i < res.length){
                res[i++] = nums[left++];
            }
        }
        for(i = 0; i < res.length && start < end; i++, start++){
            nums[start] = res[i];
        }
    }
}
```

![1713805565530](image/Record3/1713805565530.png)

### ��������

���仰�ܽ᣺ÿ�ν�һ�����ŵ���Ӧ�÷ŵ�λ�á�������˫ָ�루low��high����һ����ǰ����һ���Ӻ���ǰ����С�� pivot ��������ǰ���������� pivot �ķ�������󲿡���ָ�������ĵط����� pivot �÷ŵĵط���

˼���������ֱ������ʵ�ֿ������� ��

### ������

JAVA �е����ȶ��� PriorityQueue �ײ�Ĭ��ʹ�ö�����ʵ�֣�

**��������ʹ�� PriorityQueue ����ʵ�ֶѵĹ��ܡ�**
