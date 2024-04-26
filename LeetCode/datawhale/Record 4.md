### ���ֲ���

�۰���ҡ�Ҫ������������
����ҿ���ֻҪ��֤ÿ�εݹ�ʱ����Χ������һ�¾Ϳ��ԡ���Ϊmid�ǲ������м䣬����Ҫ�����֣����֣�������ֲ��ң���ʱ�临�Ӷ��Ͻ�����һ���ġ�

### ��ϰ��Ŀ����09�죩

#### 1.0704. ���ֲ���

#### 1.1 ��Ŀ����

**������** ����һ����������� ����һ��Ŀ��ֵ
��

**Ҫ��** ���� �������е�λ�ã�����Ҳ������򷵻� -1��

**˵����** ����Լ���  �е�����Ԫ���ǲ��ظ��ġ�

#### M��

ϰ�߶���һ�����鷶Χ��������ҿ���ֻҪ�ڱ�̵Ĺ����У�ȫ�̱���һ�£��ݹ��������ʱ������ûʲô����.
�վ�����ȡ���������ǲ���ȡ�����ܺ���⡣

#### C��

```java
class Solution {
    public int search(int[] nums, int target) {
        // �Ҳ�������ҿ��ķ�ʽ
        int start = 0;
        int end = nums.length;
        return half(nums, start, end, target);
    }
    public int half(int[] nums, int start, int end, int target){
        if(start >= end){return -1;} //���ȷǷ���ֱ�ӷ����Ҳ���
        int mid = start + (end - start) / 2;
        if(nums[mid] == target){
            return mid;
        }
        if(nums[mid] > target){
            return half(nums, start, mid, target);  // ����ҿ�������һ�¼���
        }else{
            return half(nums, mid + 1, end, target);
        }
      
    }
}
```

![1714128667740](image/Record4/1714128667740.png)

#### 2.0035. ��������λ��

#### 2.1 ��Ŀ����

**������** ����һ���ź�������� ���Լ�һ��Ŀ��ֵ ��

**Ҫ��** ���������ҵ�Ŀ��ֵ���������±ꡣ����Ҳ������򷵻�Ŀ��ֵ��˳����������λ�á�

#### M��

����Ĵ������һ��һģһ��������������ʱ����һ���Ҳ��������-1��������

�Ҳ�����λ�ã�����������λ�ڵ�λ�ã�����������ͺ��ˡ�

#### C��

```java
class Solution {
   public int searchInsert(int[] nums, int target) {
        int start = 0;
        int end = nums.length;
        return half(nums, start, end, target);
    }


    public int half(int[] nums, int start, int end, int target){
        if(start >= end){return start;} //���ȷǷ���ֱ�ӷ����Ҳ���
        int mid = start + (end - start) / 2;
        if(nums[mid] == target){
            return mid;
        }
        if(nums[mid] > target){
            return half(nums, start, mid, target);  // ����ҿ�������һ�¼���
        }else{
            return half(nums, mid + 1, end, target);
        }

    }
}
```

![1714128685885](image/Record4/1714128685885.png)

#### 3.0374. �����ִ�С

#### 3.1 ��Ŀ����

**������** ��������Ϸ������һ������ ��һ���ӿ� def guess(num: int) -> int:����Ŀ��� �����ѡȡһ���� ������ֻ��ͨ�����ýӿ����ж��Լ��²�����Ƿ���ȷ��

**Ҫ��** Ҫ�󷵻���Ŀѡȡ������ ��

#### M��

���ݷ�Χ�� 1~n����Ȼ�����۰���ҵ�һ��Ӧ�á�
���ж����������任����Ŀ�ṩ�Ľӿھͺá�

#### C��

���ʹ��֮ǰ��ģ�壬����ҿ���end = n + 1���ǿ��ܻᱬint�Ρ���������Ŀʹ������ұա�

```java
public class Solution extends GuessGame {
    public int guessNumber(int n) {
        int start = 0;
        int end = n; //����2^31-1 ����ҿ��ᳬint
        return half(start, end);
    }

    public int half(int start, int end){ //�ĳ�����ұ�
        if(start >= end){return start;} //���ȷǷ���ֱ�ӷ����Ҳ���
        int mid =  start + (end - start) / 2;
        if(guess(mid) == 0){
            return  mid;
        }
        if(guess(mid) == -1){
            return half(start, mid - 1);  // ����ұգ�����һ�¼���
        }else{
            return half(mid + 1, end);
        }

    }
}
```

![1714128700100](image/Record4/1714128700100.png)

### ��ϰ��Ŀ����10�죩

#### 1.0069. x ��ƽ����

#### 1.1 ��Ŀ����

**Ҫ��** ʵ�� int sqrt(int x) ���������㲢����  ��ƽ������ֻ�����������֣�������  �ǷǸ�������
˵����

#### M:

����ʹ���۰���ҵķ�ʽ���������ڣ��ж����������޸�һ�£�ԭ����nums[mid] ==target,���ڱ��mid * mid == target
��Ҫ������ж��߼��ǣ�������ˣ��ǿ϶��ҵ��ĸ����ԣ��������С���ǾͲ�һ������Ϊ8�ĸ���2.+����ĿҪ������������֡�������2��2��ƽ����4ȷʵС��8�������ж�С��������2����3��mid + 1��ƽ����С�ǲ������С�ˡ�

#### C:

ƽ���ǿ��� �ᱬ��������int�ġ�

```java
class Solution {
    public int mySqrt(int x) {
        int start = 0;
        int end = x / 2 + 1;  //��һ��ĵط���ʼ��
        return half(start, end, x);
    }
    public int half(int start, int end, int target){ //����ҿ�
        if(start >= end){return start;} //���ȷǷ���ֱ�ӷ����Ҳ���
        int mid =  start + (end - start) / 2;
        long squa = (long)mid * (long)mid;   // �ĳ�long�Ų��ᱬ
        long squa_ = (long)(mid+1) * (mid+1);
        if(squa == target){
            return  mid;
        }
        if(squa > target){
            return half(start, mid, target);  // ����ҿ�������һ�¼���
        }else if(squa < target && squa_ > target){  // 2^2 < 8 && 3^2 > 8,����2����ȷ�ġ�
            return mid;
        }else{
            return half(mid + 1, end, target);
        }

    }
}
```

![1714128715645](image/Record4/1714128715645.png)

#### 2.0167. ����֮�� II - ������������

#### 2.1 ��Ŀ����

**������** ����һ���±��  ��ʼ�������������е��������飺 ��һ��Ŀ��ֵ ��

**Ҫ��** ���������ҳ��������֮�͵���  �������������������������������µı�ֵ��

#### M��

����������Խ�targer����  �� = С + ��˫ָ�룬һ����ͷһ����β���ʹ��˾��ô�ָ�����Ʊ�С����С�˾���Сָ�����Ʊ��ֱ���ҵ�Ϊֹ��
���˼·һ�������ҵ�������ֻ����һ�Ρ�

#### C��

```java
class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int low = 0;
        int high = numbers.length - 1;
        int[] res = new int[2];
        while(low < high){ // �����������
            int sum = numbers[low] + numbers[high];
            if(sum == target){
                res[0] = low + 1;
                res[1] = high + 1;  //�±��1��ʼ
                return res;
            }
            else if(sum < target){
                low++;
            }else{
                high--;
            }
        }
        return res;
    }
}
```

![1714128793800](image/Record4/1714128793800.png)

#### 3.1011. �� D �����ʹ����������

#### 3.1 ��Ŀ����

���������ʹ��ϵİ��������� ���ڴ�һ���ۿ����͵���һ���ۿڡ��������а�������������
��������밴�ո�����˳��װ�ˡ���ÿ�촬��װ�ص��������ᳬ�������������������

Ҫ��������
 ���ڽ����а����ʹ�Ĵ��������������

#### M��

����Ƕ��ֲ��ҵĻ���Ҫ����һ�����ޣ�һ�����ޡ��Ƚ�ֱ�۵�������޾��ǣ�ÿ�˶�������װ����ͬ�������������Ĵ�����С�� = ������ / ������ ǰ���ǲ���С����󵥼����
������һ����Ե�һ��ġ����罫�����������ֳ� days�ݡ������ķݵ�������󣬴������޾Ͷ��������

���������Ӧ���ǿ����������񣬵�����Сһ�Ͳ����˵�����������ͻ��м�С�Ŀռ䡣
��� ��ǰ�������������������ڣ��ǿ϶��ü�

#### C��

```java
class Solution {
    public int shipWithinDays(int[] weights, int days) {
        int max_stuff = 1; // ���Ļ���������Ҫ��װ�����Ļ�
        int max_group = weights.length / days; //�������
        int sum = 0; // ����������
        int group_temp = 0;
        // ��ʼ����Ϣ
        for(int i = 0; i < weights.length; i++){
            if(weights[i] > max_stuff){
                max_stuff = weights[i];
            }
            group_temp += weights[i];
            sum += weights[i];
            if(i % days == 0){
                if(group_temp > max_group){
                    max_group = group_temp;
                    group_temp = 0;
                }
            }
        }

        int min_group = Math.min(sum / days, max_stuff); // ����������С
        max_group = Math.max(max_group, group_temp); //��������
        return half(weights, min_group, sum, days); // �������Ͻ�ֱ�����ó�sum

    }
    public int half(int[] weights, int start, int end, int days) {
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (countDays(weights, mid, days) && !countDays(weights, mid - 1, days)) {
                // ��ǰ��Сһ��Ͳ���
                return mid;
            } else if (!countDays(weights, mid, days)) {
                start = mid + 1; // ������߽�
            } else {
                end = mid - 1; // �����ұ߽�
            }
        }
        return start; // ���û���ҵ����ʵ����������Ը�����Ҫ����һ��ֵ
    }

    public boolean countDays(int[] weights, int cap, int days){
        //���ص�ǰ�����Ĵ��ܲ����ڹ涨��������
      
        int day = 1; //�������˼����ˣ�����һ��
        int i = 0;
        int temp = 0;// ��ǰװ�˶���
        while(i < weights.length){
            if(weights[i] > cap){return false;} // ��������Ķ�װ����
            temp += weights[i];
            if(temp > cap){
                temp = weights[i]; // �ŵ��ڶ��죬����ʱ������ɵ�ǰ���������
                day++;
            }
            i++; // ������α���ָ�붼Ҫ��ǰ
        }
        if(day <= days){return true;} // �涨������װ��
        return false;
    }
}
```

![1714128809565](image/Record4/1714128809565.png)
����ܳ�������Ч�����á�ѧϰһ������Ĵ��롣

�޸ķ�����

* �Ͻ����ó�һ����ɣ��½����ó���󵥸����ʹ��Stream
* �ж���˼·û�����ǲ���Ҫ����ʹ��foreach
* if (countDays(weights, mid, days) && !countDays(weights, mid - 1, days)) ��Ҫ�������жϣ�ֱ��һֱ���֣��˳�ѭ��ʱ��������ָ�뼴�ɡ�

```java
class Solution {
    public int shipWithinDays(int[] weights, int days) {
        int left = Arrays.stream(weights).max().getAsInt(); // ��С���������ܹ�װ��������
        int right = Arrays.stream(weights).sum(); // �����������һ��װ��
        while(left <= right){    // ����������ұյ�
            int mid = left + (right - left) / 2;
            if(countDays(weights, mid, days)){ // ����ɾ�����С
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return left;
    }
    public boolean countDays(int[] weights, int cap, int days){
        //���ص�ǰ�����Ĵ��ܲ����ڹ涨��������
      
        int day = 1; //�������˼����ˣ�����һ��
        int temp = 0;// ��ǰװ�˶���
        for(int weight : weights){
            temp += weight;
            if(temp > cap){
                temp = weight; // �ŵ��ڶ��죬����ʱ������ɵ�ǰ���������
                day++;
            }
        }
        if(day <= days){return true;} // �涨������װ��
        return false;
    }
}

```

���뾫���˲��٣�Ҳ������һЩ
![1714128824426](image/Record4/1714128824426.png)

### ��ϰ��Ŀ����11�죩

#### 1.0278. ��һ������İ汾

#### 1.1 ��Ŀ����

**������** ����һ������ �������Ѿ������İ汾�š�����һ�����ڼ��汾�Ƿ����Ľӿ� isBadVersion(version): ��

Ҫ���ҳ���һ�γ���İ汾�� ��

#### M��

����֮���Ǵ�����Ҳ����һ�����������ˡ�
�۰����

#### C:

```java
public class Solution extends VersionControl {
    public int firstBadVersion(int n) {
        int left = 1;
        int right = n;  // ����ұ�
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(isBadVersion(mid)){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return left; //
    }
}
```

![1714128837080](image/Record4/1714128837080.png)

#### 2.0033. ������ת��������

#### 2.1 ��Ŀ����

**������** ����һ���������� ��������ֵ������ͬ��������
 �Ǿ����������к���ֽ����ˡ���ת�������ġ��ٸ���һ������ ��

#### M��

 �ҵ�˼·�����ҵ����Ƶ�λ�ã��������Խ�����ֳ�������������Ĳ��֡�
 ������ҵ��ֽ紦֮ǰ��û��target���Ǿ����ұ߲������۰���ҡ�

 ���˼·��
 ����ʹ���۰���ң���������һ��֮���������������֣�һ����������һ���������ƶ�������ȫ������ һ�������ǣ�����Ĳ��֣�����֪����ֹ��Ҳ��֪�����ݷ�Χ�������ж�target�Ƿ������档����ȥ��һ�����ң�������һ���֡�

#### C��

```java
 class Solution {
    public int search(int[] nums, int target) {
        int left = 0;
        int right = nums.length; // ����ҿ�
        while(left < right){ // ����ҿ�������ָ�벻�����
            int mid = left + (right - left) / 2;
            if(nums[mid] == target){
                return mid;
            }
            if(nums[left] <= nums[mid]){ // �������
                if(nums[left] <= target && target < nums[mid]){
                    // ���������target�������
                    right = mid;      
                }else{
                    left = mid + 1;
                }
            }else{ // �ұ�����
                if(nums[mid] < target && target <= nums[right - 1]){
                    //��������������ұ�
                    left = mid + 1;
                }else{
                    right = mid;
                }
            }
        }
        return -1;

    }
}
```

![1714128852305](image/Record4/1714128852305.png)

#### 3.0153. Ѱ����ת���������е���Сֵ

#### 3.1 ��Ŀ����

**������** ����һ������ �������������龭������ת���õ��ġ�������ת����δ֪�������в������ظ�Ԫ�ء�

**Ҫ��** �ҳ������е���СԪ�ء�

#### M:

����һ�����ƣ���ʵ��ת���ζ����Կ�����תһ�Σ���δ֪��λ��������һ��K����
�۰�֮�����򲿷ֵ���Сֵ������֪���ģ���һ���ؿ��Եݹ�ִ�С�

#### C:

```java
class Solution {
    public int findMin(int[] nums) {
        return half_min(nums, 0, nums.length);
    }
    public int half_min(int[] nums, int left, int right){
        if(left == right){return nums[left - 1];}
        //�۰�����С������ҿ�
        int mid = left + (right - left) / 2;

        if(nums[left] <= nums[mid]){
            //�������
            return Math.min(nums[left], half_min(nums, mid + 1, right)); // ��ߵ���Сֵ���ұ���Сֵ��С����һ��
        }else{
            //�ұ�����
            return Math.min(half_min(nums, left, mid), nums[mid]);
        }
    }
}
```

 �о��ռ�������ʹ���˵ݹ飬����ռ�ö��ˡ�
 ![1714128865931](image/Record4/1714128865931.png)

 ������⣺
 ѧϰһ���ٷ��ⷨ���ǵݹ顣
 �ҵ�����ǣ�������һ�����ۣ���Сֵһ��������Ĳ��֡��������ԭ�������������أ��Ǿ�λ���󲿷��ˡ������ж����������Ӧ���ǱȽ�mid��right�Ĵ�С��ϵ���������Ըĳɵ����ķ�ʽ��
 ���Լ��ĳ����£�
�߽������Ŀ��ǻ��ǲ�̫����

```java
class Solution {
    public int findMin(int[] nums) {
        int left = 0;
        int right = nums.length - 1; // ����ұ�
        while(left < right){
            int mid = left + (right - left) / 2;
            if(nums[mid] < nums[right]){ // ���Ҳ���������
                right = mid;  
            }else{
                left = mid + 1; // mid ���Բ�Ҫ����Ϊnums[right]������С
            }
        }
        return nums[left]; // �������
    }
}
```

![1714128889694](image/Record4/1714128889694.png)

### ���Ľ׶��ĵ�

��ѧϰ�۰���ҵĹ����У��Ҹ������ڲ������ұյı߽���ơ���������ڵݹ�ʹ��ʱ����ȷ�����µ���֮���һ���ԡ�������ѭ����䣨while�����ж�����ʱ���ҳ���˼����ʹ��"left < right" ���� "left <= right"��Ϊ��ȷ����һ�㣬�һ������Լ����뵽�㷨�У�������Ƿ�����������߽�ʱ���ʵ� "nums[left]" ���Ԫ�ء����⣬���ݹ�ʵ�ָ�д��ѭ��ʵ��Ҳ����Ҫ������ϰ�ļ��ܡ��ҷ��֣�����������⣬��ѭ����д������Ӽ�࣬���������ο��ǵݹ���������������
