### ˫ָ�����֪ʶ���� 12 \~ 13 �죩

#### ��ײָ��

һ����ͷ�����ߣ�һ���Ӻ���ǰ��,�������������顣
һ�������������������ָ��������Ҳ���Ǳ�����һ�����顣

##### ���÷�Χ

* ������������������ĳЩԼ��������һ��Ԫ�����⣺������ֲ��ҡ�����֮�͵����⡣
* �ַ�����ת���⣺��ת�ַ��������������ߵ������Ƶ����⡣

##### 167. ����֮�� II - ������������ - ���ۣ�LeetCode��

����һ���±�� 1��ʼ�������������е��������飺 ��һ��Ŀ��ֵ target��

˼·������Ŀ�Ѿ������ˣ�target = С + ����˽�С��ʼ������С�����ʼ���������������������ص㣬����һ����ײָ��ľ�����Ŀ��

##### 2.5 ��֤���Ĵ�

���Ĵ������Ŷ��ͷ��Ŷ���һ�����ַ�����
��һ��˵���ǣ���һ�������һ����ͬ���ڶ����͵����ڶ�����ͬ.....
����һ����ʹ�ö�ײָ���˼·�ͺ���ȷ�ˡ�

��Ŀ������������Ҫת��ͳһ��Сд�������µ�����ĸ�����֡���Ҫһ��Ԥ����

````java
class Solution {
    public boolean isPalindrome(String s) {
        // �����д�д�ַ�ת��ΪСд�ַ������Ƴ����з���ĸ�����ַ�֮��
        StringBuffer bf = new StringBuffer();
        for(char c : s.toUpperCase().toCharArray()){
            if(Character.isLetterOrDigit(c)){
                bf.append(c);
            }
        }
        int low = 0, high = bf.length() - 1;
        while(low <= high){   //����ָ����������������ܳ���
            if(bf.charAt(low++) != bf.charAt(high--)){
                return false;
            }
        }
        return true;
    }
}
````

#### 2.6 **ʢ���ˮ������**

�ҳ����е������ߣ�ʹ�������� x **�Ṳͬ���ɵ�����������������ˮ**
˼·��
�������ֵ��һ����˵�����ǿ϶���Ҫ�ģ����Ǳ����ķ�����ʲô������һ����ʼ������ѡ��ľ��ǿ������ʱ�򣬼�һ������������ߣ�һ�������ұߡ����Ƕ�ײָ�롣������������ָ�벻��ͬʱ�ƶ��ˡ���Ϊ��ȱ�С�������ǻ��С�ģ�Ҫ���ø����������**ֻ���ø�С�ĵ�������Եر�󡪡��ƶ���С�İ塣**
����������
����ָ�룬��ʼλ�����������˵㣬��¼��ǰ������ÿ�ε�������С�ĵ������м䷽���ƶ���ÿ�μ��������������ֱ������ָ���������˳�ѭ����

```java
class Solution {
    public int maxArea(int[] height) {
        int low = 0, high = height.length - 1;
        int v = 0;
        while(low < high){ // ������������Ѿ�Ϊ0
            v = Math.max(v, Math.min(height[low], height[high]) * (high - low));
            if(height[low] < height[high]){   // С�İ��ƶ�
                low++;
            }else{
                high--;
            }
        }
        return v;
    }
}
```

#### ����ָ��

����ָ���ƶ��ķ�����ͬ��
����ָ��һ�����ڴ��������е��ƶ���ɾ��Ԫ�����⣬���������е��ж��Ƿ��л����������⡣

##### 3.4 ɾ�����������е��ظ���

��ԭ��������У�������Ϊһ��ָ���������ʣ�һ��ָ������ָʾԪ�ش��λ�ã����ڱ����ʹ���Ԫ��û�б�Ҫ���������Կ���ֱ��ʹ��ԭ�������顣������ʽҲ����Ϊ����ָ�룬��֮������ָ��ֵ���ͬ�Ľ�ɫ��
ԭ��������ɾ��һ��Ԫ����Ҫ�漰�ƶ��Ĳ��������ڱ�������¸�ֵ��һ���µ����顣

```java
class Solution {
    public int removeDuplicates(int[] nums) {
        if(nums.length == 1){return 1;}
        int low = 1;     //���ظ���Ԫ�ش�ŵ�λ��
        int fast = 1; // ��һ��Ԫ�ؿ϶�Ҫ���µ�
        int k = 1;
        while(fast < nums.length){
            if(nums[fast] != nums[fast - 1]){
                nums[low++] = nums[fast++];
                k++;
            }else{    //�����ظ�Ԫ��ֱ����ǰ
                fast++;
            }
        }
        return k;
    }
}
```

#### 4. ����˫ָ��

����ָ���ڲ�ͬ���������ƶ����ȷ�˵���鲢�����е���������ϲ���һ������
����ģ����˵��

* ��ȷʲôʱ������ָ��һ��ǰ��
* ʲôʱ������һ������ǰ��

##### 4.4 ��������Ľ���

���������飬������������Ľ������ظ�Ԫ��ֻ����һ�Ρ�

��Ҫ����������������򡣴�ͷ��ʼ����

* �������Ԫ����ȣ���ͬʱǰ��һ��(�жϵ�ǰԪ���Ƿ��Ѿ�����¼)
* �����ý�С��ָ��ǰ����������һ��ѭ��
* ֱ��һ��ָ���ߵ�β�ˣ������˳�ѭ���ˣ���һ��������û������ν�ˡ�

```java

class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        Arrays.sort(nums1);
        Arrays.sort(nums2);
        int[] res = new int[Math.max(nums1.length, nums2.length)];
        int left = 0, right = 0, index = 0;
        while(left < nums1.length && right < nums2.length){
            if(nums1[left] == nums2[right]){
                if(index == 0 || nums1[left] != res[index - 1]){
                    //δ����¼��
                    res[index++] = nums1[left];
                }
                left++;right++;
            }else if(nums1[left] < nums2[right]){
                left++;
            }else{
                right++;
            }
        }
        return Arrays.copyOfRange(res, 0, index);
    }
}
```

### ��ϰ��Ŀ���� 12 �죩

#### 1.0344. ��ת�ַ���

����һ���ַ����� �����䷴ת.����ʹ�ö��������ռ䣬����ԭ���޸���������

#### M:

���жϻ��Ĵ���˼·��һ���ģ����ַ������������飬����ָ��һ����ͷ��һ����β������
����ײָ�룩

#### C:

```java
class Solution {
    public void reverseString(char[] s) {
        int left = 0, right = s.length - 1;
        while(left < right){ //����ָ���������Ǹ��ַ����Բ��ò�����
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;right--;
        }
    }
}
```

![1714363934307](image/Record5/1714363934307.png)

#### 2.0345. ��ת�ַ����е�Ԫ����ĸ

����һ���ַ��� ��

Ҫ�󣺽��ַ����е�Ԫ����ĸ���з�ת��

Ԫ����ĸ���� 'a'��'e'��'i'��'o'��'u'���ҿ����Դ�Сд������ʽ���ֲ�ֹһ�Ρ�

#### M:

����һ���˼·һ�����뷴ת�ǿ϶�����Ҫ����ָ��ġ���ͬ�ĵ������ҵ���һ����Ҫ��ת��λ�á�Ҳ����˵��left��ҪȥѰ����һ����Ҫ��ת��λ�ã�rightҲ��Ҫ������һ�������ǵ���һ��λ�þ������ڵ���һ�����ӡ�
Ҳ����˵�����Ǹ�����Ҫһ��whileȥѰ����һ��Ԫ�أ���Ԫ�����ַ�����
����ײָ�룩

#### C:

�ҽ��ж���Ԫ����װ��һ������

```java
class Solution {
public String reverseVowels(String s) {
char\[] str = s.toCharArray();
int left = 0, right = str.length - 1;
while(left < right){ // �����Ͳ���
// leftѰ����Ҫ��ת�ĵط�
while(left < right && !checkChar(str\[left])){left++;}
// rightѰ����Ҫ��ת�ĵط�
while(left < right && !checkChar(str\[right])){right--;}            char temp = str[left];
            str[left] = str[right];
            str[right] = temp;
            left++;right--;
        }
        return new String(str);
    }
    public boolean checkChar(char c){
        // ���ַ�ת��ΪСд�Խ��бȽ�
        char lowercaseC = Character.toLowerCase(c);        // ʹ������������ַ��Ƿ�ΪԪ����ĸ
        if (lowercaseC == 'a' || lowercaseC == 'e' || lowercaseC == 'i' || lowercaseC == 'o' || lowercaseC == 'u') {
            return true;
        } else {
            return false;
        }
    }
```

![1714364017588](image/Record5/1714364017588.png)


#### 3.0015. ����֮��

##### 3.1 ��Ŀ����

**������** ����һ���������� ��
**Ҫ��** �ж�  ���Ƿ��������Ԫ�� a, b, c, ����a + b + c = 0���ҳ���������Ҫ�󣬲��ظ�����Ԫ��

##### M��

�����͵�ʱ�����������������Կ��ԱȽϺõ��ж���������ָ��Ӧ��˭ȥ�ƶ�����ˣ��Ƚ�������������Ҳ�ȽϺ�������Ŀ˵���ظ���Ԫ���Ҫ�󡣽���Ŀת���� A + target = 0
target = b + c��bc��������Χ��A ���ұߡ�����������ģ������ⲿ�ֿ������������͵�������
��һ����������ҪԪ��ȥ�ء���-1��-1��0��1��
����������������������õ�����\[-1,0,1]����Ȼ����-1�ֱ�ָ����ͬλ�õ�Ԫ�أ�����Ԫ��Ľ����һ���ġ�

������Ԫ�鶼������ģ������ҿ��Է���رȽ�������Ԫ���Ƿ���ȡ�
����ײָ�룩

###### GPT�ĸĽ������

* ��Ҫ��List�ıȽϣ���ʱ�䡣
* aԪ�ص�ѡ���ʱ��Ӧ��ȥ�أ�������Щ�ظ��ġ�
* ͬ�������ҵ�a��b��c֮�� ��b��cҲһ��������Щ�ظ��ģ�����һ���Ͳ�����ListԪ���ȥ��

##### C��

```java
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        int a = 0;
        int top = -1; // res��ջ��
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        while(a < nums.length - 2){ // ����bc�Ŀռ�
            if(a == 0 || nums[a] != nums[a - 1]){ // �����ظ���a
                //Ѱ�ң�a,b,c��
                int b = a + 1, c = nums.length - 1;
                while(b < c){
                    int sum = nums[a] + nums[b] + nums[c];
                    if(sum == 0){
                        res.add(Arrays.asList(nums[a], nums[b], nums[c]));
                        //�����ظ���b��c
                        while(b < c && nums[b] == nums[b + 1]) b++;
                        while(b < c && nums[c] == nums[c - 1]) c--;
                        b++;c--; // ��һ�������b c��λ��
                    }else if(sum < 0){
                        b++;
                    }else{
                        c--;
                    }
                }
                //���У�i, X,X����������
            }
            a++;
        } 
        return res;
    }

}
```

![1714364031885](image/Record5/1714364031885.png)
ʱ�仹�ǲ���ѽ��

### ��ϰ��Ŀ���� 13 �죩

#### 1.0027. �Ƴ�Ԫ��

1.1 ��Ŀ����
����������һ������ ����һ��ֵ val��

Ҫ�󣺲�ʹ�ö�������ռ䣬��������������ֵ���� valֵ��Ԫ���Ƴ��������ҷ���������ĳ��ȡ�

#### M:

����ȥ�صı�׼���ͺ��ˣ�����ָ�룬һ���������ʣ�һ��ָʾ��д��λ��
���ָ���λ����������Ҫ���صĳ���
(����ָ��)

#### C:

```java
class Solution {
    public int removeElement(int[] nums, int val) {
        int slow = 0, fast = 0;
        while(fast < nums.length){
            if(nums[fast] != val){
                nums[slow++] = nums[fast];
            }
            fast++;
        }
        return slow;
    }
}
```

![1714364046112](image/Record5/1714364046112.png)

#### 2.0080. ɾ�����������е��ظ��� II

##### 2.1 ��Ŀ����

**������** ����һ���������� ��

**Ҫ��** ��ԭ����ռ������ɾ���ظ����� �����ϵ�Ԫ�أ�������ɾ����������³��ȡ�

#### M:

��֮ǰ�Ļ���˼·�ϣ�����һЩ�Ķ�����Ҫһ���������������ظ��˼��Ρ������ǰԪ�ظ�ǰһ��Ԫ�ز�һ�����������ó�һ�����һ����������һ�����ҵ�ǰԪ��¼�룩�������ǰһ��һ������������ʾΪ2��fast���������Ԫ�ء�

(����ָ��)

#### C:

```java
class Solution {
    public int removeDuplicates(int[] nums) {
        //������ 1 <= length�����ĵشӵڶ���Ԫ�ؿ�ʼ
        int slow = 1, fast = 1, count = 1;
        while(fast < nums.length){
            if(nums[fast] != nums[fast - 1]){ // ��ǰһ����һ�������¼���
                nums[slow++] = nums[fast];
                count = 1;
            }else{
                if(count < 2){ // ��û��¼��2��
                    nums[slow++] = nums[fast];
                    count++;
                }else{
                    // �Ѿ�����¼��2����
                  
                }
            }
            fast++; //����ʲô�����Ҫǰ��
        }
        return slow;
    }
}
```

![1714364060060](image/Record5/1714364060060.png)

#### 3.0925. ��������

#### 3.1 ��Ŀ����

**������** �����������ʹ�ü��������������֡�ż�����ڼ����ַ�ʱ���������ܻᱻ���������ַ����ܱ����� �λ��Ρ�

���ڸ����������ֵ��ַ��� ���Լ�ʵ��������ַ��� ��

#### M��

����names.length <= typed.length, names��ָ��ҲҪ�����Ŷԡ�
��Ҫ��һ��ʲô����£�����ֱ�ӷ���false��Ӧ��˵��һ��Ӧ����ȵ��ַ������ʱ��˵�������ַ�������ȡ�
����һ��names���ַ�c��ǰһ������ͬʱ������typed��ָ�������ظ����ַ���ֱ��һ���µ��ַ����֣�Ȼ��ȶ�c�����ַ��Ƿ�ƥ�䣬��ƥ��˵���Ͳ������ֵ��ظ����롣
�˳�ѭ��ʱ����Ҫ���һ�£������Ƿ�ƥ���꣬���µ��ַ���Ϊ�ظ����ַ�
������ָ�룩

#### C��

```java
class Solution {
    public boolean isLongPressedName(String name, String typed) {
        char[] nameArr = name.toCharArray();
        char[] typedArr = typed.toCharArray();
        int left = 0, right = 0;   //left  - name, right - typed
        while(left < nameArr.length && right < typedArr.length){
            if(nameArr[left] != typedArr[right]){
                //��ǰԪ�ز���ȣ��϶������ֶ���
                return false;
            }else{
                left++;right++;  //ƥ�䣡����ָ�빲ͬǰ��
                if(left < nameArr.length && nameArr[left] != nameArr[left - 1]){
                    // �����ǰname�ַ�����Ҫ��ǰһ����ͬ��
                    //������typed������һ����ͬ�ַ�(��Ϊ��ǰ�ַ����� ��ǰһ�����ظ�)
                    while(right < typedArr.length && typedArr[right] == typedArr[right - 1]) right++;
                }
            }
        }
        if(left < nameArr.length){
            //���벻�����϶���ƥ��
            return false;
        }
        while(right < typedArr.length){
            //�����µ��ַ�������ͬһ���ַ�
            if(typedArr[right] != typedArr[right - 1]) return false;
            right++;
        }
        return true;
    }
}
```

![1714364072622](image/Record5/1714364072622.png)

### �������ڻ���֪ʶ���� 14 �죩

�̶����ȴ��ڣ����ڴ�С�ǹ̶��ġ�
�������ȴ��ڣ����ڴ�С�ǲ��̶��ġ�

* ����������������Ĵ��ڡ�
* �����С�����������Ĵ��ڡ�
  ����ָ��������ķ�Χ����һ�����ڣ��ʺ�������������飨�����У�����Ŀ��
  ����Ĺؼ������Ѱ�ҵ�����ָ���ƶ����߼���

#### 3. �̶����Ȼ�������

##### 3.3 ��СΪ K ��ƽ��ֵ���ڵ�����ֵ����������Ŀ

#### 3.3.2 ��Ŀ����

**������** ����һ���������� ����������  ��  ��

**Ҫ��** ���س���Ϊ  ��ƽ��ֵ���ڵ��� ����������Ŀ��

#### M��

#### C��

�̶����ȵĴ��ڣ���Ҫ��ģ�ⴰ���ƶ����ɡ�
ά�������ڵ��ܺ�sum���ɡ�

```java
class Solution {
    public int numOfSubarrays(int[] arr, int k, int threshold) {
        // 1 <= arr[i] <= 104
        int left = 0, right = 0, sum = 0, res=0;
        while(right < arr.length){
            sum += arr[right];
            if(right - left + 1 >= k){ // ��ǰ����=K
                if(sum >= k * threshold) res++;
                sum -= arr[left++];
            }
            right++;
        }
        return res;
    }
}
```

#### 4. �������Ȼ�������

#### 4.3���ظ��ַ�����Ӵ�

**������** ����һ���ַ��� ��

**Ҫ��** �ҳ����в������ظ��ַ�����Ӵ��ĳ��ȡ�
ֻҪ���ظ���right��һֱ��ȡ����֮���㳤��leftһֱǰ�����˵��ַ���ֱ���˵�right������ظ����ַ���Ȼ��right���Լ���ǰ�����ظ����̡�
��Ҫ��ϣ����¼һ�³��ֵ��ַ���

#### C��

```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
        char[] str = s.toCharArray();
        // ����һ��HashMap���洢�ַ������ǵļ���
        Map<Character, Integer> charCountMap = new HashMap<>();
        int left = 0, right = 0; //0 <= s.length <= 5 * 104
        int max_length = 0;
        while(right < str.length){
            if(charCountMap.getOrDefault(str[right], 0) > 0){
                //�����ظ� ���㳤��
                max_length = Math.max(max_length, right - left);
                // �˳��ظ����ַ���
                while(str[left] != str[right]){
                    charCountMap.put(str[left], 0);
                    left++;
                }
                 //�˳��ظ����ַ�, ���ַ�����1�Σ���right��
                left++;
            }else{
                charCountMap.put(str[right], 1);
            }
            right++;
        }
        return Math.max(max_length, right - left);
    }
}
```

#### 4.5 �˻�С��K��������

#### 4.5.1 ��Ŀ����

#### 4.5.2 ��Ŀ����

����������һ������������ ������ ��

Ҫ���ҳ��������ڳ˻�С��  ��������������ĸ�����

#### M:

��һ��������ȫ���˻�СK����ô����ÿ��λ�õ�right���γɵ� ��right - left + 1 �����鶼������Ҫ��ġ�
������ÿ��Ѱ�Ҵ�left��Ϊͷ����ķ���Ҫ�������ʱ������ͬʱ��������λ����leftΪ��ʼ�ķ���Ҫ������顣
ͦ�����ġ���Ҫ����һ�ᡣ��������

---

����˼·���£�

1. left,��ʾ��leftΪ����������right��ʾ��leftΪ��㣬�����ܴﵽ����󳤶ȵ�����Ľ�β�����仰˵rightҪ��������һ����left,right�γɵ�����ͳ�K�ˡ�
2. ��left��right�γɵ�������ڣ���leftΪ�������飬��right - left + 1,���������ҿ�����right - left.
3. �������̾��ǰ�ÿ��left�Ķ�����һ�Ρ�
4. ÿ��һ��left�ҵ��������right֮�󣬼���һ���ܹ�������Ȼ��leftǰ��һ�£��������left�����........

---

#### C:

�����̵�ʱ��������ͨ��Ҫ���ǽ�β��˭�����������˼·�ڱ�̵�ʱ��ʵ�����˸ı䣬ÿ�ζ�������right��β�Ĵ����У����Դ��ڶ��ٺϷ��Ľ⡣��Ϊ��leftΪͷ��˼·����rightΪβ��˼·��ʵ��һ���ġ�

```java
class Solution {
    public int numSubarrayProductLessThanK(int[] nums, int k) {
        //����������һ���ע���ڽ�β��
        // ��right��β�ģ��Ϸ������ж��ٸ���
        int left = 0, right = 0, count = 0;
        int times = 1; // ��ʾ�����ڵĳ˻�[left, right]����ұ�
        while(right < nums.length){
            times *= nums[right];
            while(times >= k && left <= right){ //��ǰ��right��β�Ĵ��ڲ���������������Ѱ����right��β�Ĵ��ڣ��Ϸ����ܸ�����
                times /= nums[left];
                left++;
            }
            count += right - left + 1; // ��rightΪ��β�ĺϷ��ĸ���
            right++;
        }
        return count;

    }
}
```

### ��ϰ��Ŀ���� 14 �죩

#### 1.0643. ���������ƽ���� I

#### 1.1 ��Ŀ����

**������** ����һ����  ��Ԫ����ɵ��������� ��һ������ ��

**Ҫ��** �ҳ�ƽ��������ҳ���Ϊ
�����������飬����������ƽ������

#### M:

�������Ŀ���̶����ȵĴ��ڡ�����ָ��һ���ƶ����ִ��ڳ��Ȳ��䡣

(�̶����ȴ���)

#### C:

```java
class Solution {
   public double findMaxAverage(int[] nums, int k) {
       int left = 0, right = k;
       int sum = Arrays.stream(nums, 0, k) // �����±�0���������±�5
               .sum();
       double avg = Arrays.stream(nums, 0, k) // �����±�0���������±�5
               .average()
               .orElse(0.0); // ���û��Ԫ�أ�Ĭ�Ϸ���0.0;
       while(right < nums.length){
           sum += nums[right++];
           sum -= nums[left++];
           avg = Math.max(avg, (double) sum / k);
       }
       return avg;      
   }
}
```

![1714364095247](image/Record5/1714364095247.png)

#### 2.0674. �������������

#### 2.1 ��Ŀ����

**������** ����һ��δ����������� ��

**Ҫ��** �ҵ�������������������У������ظ����еĳ��ȡ�

#### M��

��������Ŀ����������Ƶģ�ʲô�ɽ�壬��ڶ������е����ơ�

�����������о�����Ҫ���ڣ�left��right�������������һ�������������С�

* ��ʼ����left right = 0   ���right���Ե�����Nums\[right] > nums\[right - 1]��������rightһֱǰ����ֱ��һ������������.
* ����һ�³��ȡ�Ȼ��left���õ�right��ǰλ��
* �ظ�����

���䳤���ڣ�

#### C��

ע���ǵ����������½�����ȵĽ���Ҫ����

```java
class Solution {
    public int findLengthOfLCIS(int[] nums) {
        // 1 <= nums.length <= 10^4
        int left = 0, right =1, max_length = 1;
        while(right < nums.length){
            while(right < nums.length && nums[right] > nums[right - 1]) {right++;} //�ҵ�һ���½��ĵ�
            max_length = Math.max(max_length, right - left);
            // �ҵ���һ�������ĵ�
            while(right < nums.length && nums[right] <= nums[right - 1]) {right++;}
            left = right - 1;
        }
        return max_length;
    }
}

```

![1714364109025](image/Record5/1714364109025.png)

#### 3.1004. �������1�ĸ��� III

#### 3.1 ��Ŀ����

**������** ����һ���� �� ��ɵ����� ���ٸ���һ������
k�������Խ� k��ֵ�� 0�䵽1 ��

**Ҫ��** ���ؽ����� �������������ĳ��ȡ�

#### M:

�������⣬�䳤�Ĵ��ڡ�ֻҪ�������0����K����rightһֱ��ȡ��ֱ������һ��0������һ�³��ȡ�Ȼ��right��ȡ��һ��0��left����ֱ������һ��0

���䳤���ڣ�

#### C:

ȫ0 ��k= 0 ���������

```java
class Solution {
    public int longestOnes(int[] nums, int k) {
        // 1 <= nums.length <= 105
        int left = 0, right = 0, max_length = 0, count = 0; // ������0
        while(right < nums.length){
            if(nums[right] == 0 && ++count > k){ //���߼��ж�
                max_length = Math.max(max_length, right - left);
                // left ����һ��0 ���ҵ���һ��0����
                while(left <= right && nums[left] == 1) left++;
                left++; //�������0
                count--;  //���ڻ���K��0
            }
            right++;
        }
        return Math.max(max_length, right - left); //��β�Ļ�����һ��
    }
}
```

![1714364128438](image/Record5/1714364128438.png)

### ��һ�׶�С��

�о�˫ָ�룬��ײָ��Ϳ���ָ�����Ŀ���Ǻý�ġ�Ψһ�ѵ��������Ŀ��ָ�������ӵ����ࡣ����3����4��������������һ������Щ���εĽ�ɫ�Ƿ��ʣ���Щ��ָ��洢�����Ͳ�̫�����ˡ�
��������Ҳһ����ʲôʱ���ƶ����ң����µĲ��Զ��ǱȽϿ��鹦���ġ�ֻ�ܶ�������С�
