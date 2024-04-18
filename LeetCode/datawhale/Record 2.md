# LeetCode Notes by Datawhale - 18 April 2024

Between Zeron and One, lies the infinite possibility! Hey there, this is Zeron!

�⼸��ѧϰ������Ķ��塢�����������Ԫ�صķ�ʽ����ά���������Լ���ͬ��������������ʵ�֡�ͬʱѧϰ�˷�������Ԫ�ء���������Ԫ�ء���������Ԫ�ء��ı�����Ԫ���Լ�ɾ������Ԫ�صķ���ʵ�֣���ѧϰ������Ӧ��ʱ�临�Ӷȡ�����ѡȡ�˼��� leetcode �й���������������ϰ��

���������������򵥵����ݽṹ��������ʵ�����Ա��˳��ṹ�洢�Ļ�������ʹ��һ���������ڴ�ռ䣬���洢һ�������ͬ���͵����ݡ�

���������ص��֧��������ʡ���������Ԫ�ء��ı�����Ԫ�ص�ʱ�临�Ӷ�Ϊ O(1)��������β�����롢ɾ��Ԫ�ص�ʱ�临�Ӷ�Ҳ�� O(1)����ͨ����²��롢ɾ��Ԫ�ص�ʱ�临�Ӷ�Ϊ O(n)��

### һ��0066 ��һ

![1713454592430](image/Record2/1713454592430.png)

˼· 1���Ƚ��б��е�ֵת��Ϊʮ������������һ����ͨ���ַ���ת�����б����ʽ���ء�

```python
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        res=0
        for i in range(len(digits)):
             res+=digits[i]10*(len(digits)-1-i)
        res+=1
        return [int(x)for x in str(res)]
```

˼· 2����ԭ�б��н��в������������б�֮ǰƴ��һ�� 0 ��ȷ����λ����ѭ�������н����жϣ�����������Ϊ 10��������������� 0��ǰһλ��+1������ж�����λ��ֵΪ 0�����������Ϊ 1 ��ʼ���б�����ȫ�������

```python
digits = [0] + digits
        digits[len(digits) - 1] += 1
        for i in range(len(digits)-1, 0, -1):
            if digits[i] != 10:
                break
            else:
                digits[i] = 0
                digits[i - 1] += 1

        if digits[0] == 0:
            return digits[1:]
        else:
            return digits
```

### ����0724 Ѱ������������±�

![1713454632572](image/Record2/1713454632572.png)

˼· 1�������б�������ĿҪ�������ж������������

```python
class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        # for i in range(len(nums)):
        #     if i==0 and sum(nums[i+1:])==0:
        #         return i
        #     if i==len(nums)-1 and sum(nums[0:len(nums)-1])==0:
        #         return i
        #     if sum(nums[0:i])==sum(nums[i+1:]):
        #         return i
        # return -1
```

˼· 2����������ѭ������һ������б�Ԫ�ص��ܺͣ��ڶ��ο�ʼ�ж���ӵĺ͵������ټ��ϵ�ǰ����Ԫ�ص�ֵ�Ƿ�����ܺͣ������ڣ���Ϊ�����±ꡣ

```python
sum = 0
        for i in range(len(nums)):
            sum += nums[i]
        curr_sum = 0
        for i in range(len(nums)):
            if curr_sum * 2 + nums[i] == sum:
                return i
            curr_sum += nums[i]
        return -1
```

### ����0189 ��ת����

![1713454660218](image/Record2/1713454660218.png)

˼· 1������������ֱ���ȶ���ת���������б���ȡ�࣬�ж�ʵ�����Ƶı仯ֵ���ٽ����� k ���б�Ԫ��ֵ��ʣ����б�Ԫ��ֵƴ�Ӽ��ɡ�

```python
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        # k%=len(nums)
        # nums[:]=nums[-k:]+nums[:-k]
```

˼· 2����ת����

```python
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        n = len(nums)
        k = k % n
        self.reverse(nums, 0, n-1)
        self.reverse(nums, 0, k-1)
        self.reverse(nums, k, n-1)
    def reverse(self, nums: List[int], left: int, right: int) -> None:
        while left < right :
            tmp = nums[left]
            nums[left] = nums[right]
            nums[right] = tmp
            left += 1
            right -= 1
```

### �ġ�0485 ������� 1 �ĸ���

![1713454745999](image/Record2/1713454745999.png)

˼· 1��˫ָ�뷨�������������ָ�룬�������飬��ǰ��������Ϊ 1 ʱ�����ָ������һ��λ�ã�ͬʱ������󳤶ȣ�����ָ��ļ����������Ϊ 1 ʱ�����ָ������һ��λ�ã�����ָ���Ƶ���ָ��λ�ã�������һ�����м��㡣

```python
class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        slow=0
        fast=0
        max_len=0
        for i in range(len(nums)):
            if nums[i]==1:
                fast+=1
            else:
                fast+=1
                slow=fast
            max_len=max(max_len,fast-slow)
        return max_len
```

˼· 2��һ�α���

```python
class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        ans = 0
        cnt = 0
        for num in nums:
            if num == 1:
                cnt += 1
                ans = max(ans, cnt)
            else:
                cnt = 0
        return ans
```

### �塢0238 ��������������ĳ˻�

![1713454780578](image/Record2/1713454780578.png)

˼·������ѭ�����ȹ���һ����ԭ���鳤����ͬ��ȫ 1 ���飬�ٷֱ��������Ԫ�س˻���ע��߽����������� 0 �� len(nums)-1 ���ֱ�û����Ԫ�غ���Ԫ�ء�

```python
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        res=[1 for _ in range(len(nums))]

        left=1
        for i in range(len(nums)):
            res[i]*=left
            left*=nums[i]

        right=1
        for j in range(len(nums)-1,-1,-1):
            res[j]*=right
            right*=nums[j]
        return res

```

### ����0498 �Խ��߱���

![1713454835162](image/Record2/1713454835162.png)

˼·���ҹ���+���Ǳ߽�����

```python
class Solution:
    def findDiagonalOrder(self, mat: List[List[int]]) -> List[int]:
        rows = len(mat)
        cols = len(mat[0])
        count = rows * cols
        x, y = 0, 0
        ans = []

        for i in range(count):
            ans.append(mat[x][y])

            if (x + y) % 2 == 0:
                # ���һ��
                if y == cols - 1:
                    x += 1
                # ��һ��
                elif x == 0:
                    y += 1
                # ���Ϸ���
                else:
                    x -= 1
                    y += 1
            else:
                # ���һ��
                if x == rows - 1:
                    y += 1
                # ��һ��
                elif y == 0:
                    x += 1
                # ���·���
                else:
                    x += 1
                    y -= 1
        return ans

```

### �ߡ�0073 ��������

![1713454881567](image/Record2/1713454881567.png)

˼·�������������ֵ���ֱ�Ԥ�ȱ�ǵ�һ�к͵�һ�У���������Ŀ����ʹ����Ԫ�����޸�ʱ���Բ�����ֵ���Ӷ�Ӱ������������������£����ȱ�����һ�к͵�һ�У�������Ԫ�أ������ֵ��Ϊ True,������������ʱ���Ὣ��һ�л��һ��Ԫ��ȫ��Ϊ 0.�ٱ���ʣ��Ԫ�أ���Ϊ 0���򽫵�һ�л��ߵ�һ�ж�Ӧ��Ԫ����Ϊ 0��������ɺ��ٽ���һ�α�����������ʣ��Ԫ����Ϊ 0

```python
m = len(matrix)
        n = len(matrix[0])
        flag_col0 = False
        flag_row0 = False
        for i in range(m):
            if matrix[i][0] == 0:
                flag_col0 = True
                break

        for j in range(n):
            if matrix[0][j] == 0:
                flag_row0 = True
                break

        for i in range(1, m):
            for j in range(1, n):
                if matrix[i][j] == 0:
                    matrix[i][0] = matrix[0][j] = 0

        for i in range(1, m):
            for j in range(1, n):
                if matrix[i][0] == 0 or matrix[0][j] == 0:
                    matrix[i][j] = 0

        if flag_col0:
            for i in range(m):
                matrix[i][0] = 0

        if flag_row0:
            for j in range(n):
                matrix[0][j] = 0

```

### �ˡ�0048 ��תͼ��

![1713454926791](image/Record2/1713454926791.png)

˼·��ԭ����ת

��Ҫע�����һ����ת�Ĵ�����������Ԫ�ظ���Ϊż��ʱ��ȫ����ת����Ϊ����ʱ��������Ԫ�ز���ת��

```python
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        n = len(matrix)

        for i in range(n // 2):
            for j in range((n + 1) // 2):
                matrix[i][j], matrix[n - j - 1][i], matrix[n - i - 1][n - j - 1], matrix[j][n - i - 1] = matrix[n - j - 1][i], matrix[n - i - 1][n - j - 1], matrix[j][n - i - 1], matrix[i][j]

```

### �š�0054 ��������

![1713454975033](image/Record2/1713454975033.png)

˼·���������������߽磨�ϡ��¡����ң���������ʱ��˳��ӱ߽������η���Ԫ�أ����ӽ��߽�ʱ�����±߽磬��С��Χ��ֱ���߽���ײ���������ʡ�

```python
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        if not matrix: return []
        l, r, t, b, res = 0, len(matrix[0]) - 1, 0, len(matrix) - 1, []
        while True:
            for i in range(l, r + 1): res.append(matrix[t][i]) # left to right
            t += 1
            if t > b: break
            for i in range(t, b + 1): res.append(matrix[i][r]) # top to bottom
            r -= 1
            if l > r: break
            for i in range(r, l - 1, -1): res.append(matrix[b][i]) # right to left
            b -= 1
            if t > b: break
            for i in range(b, t - 1, -1): res.append(matrix[i][l]) # bottom to top
            l += 1
            if l > r: break
        return res
```

### ʮ��0059 �������� II

![1713455046694](image/Record2/1713455046694.png)

˼·�������������˼·�������ƣ���ͬ����Ҫ�ֶ�����һ���վ��󣬽� index �� 1 ��ʼ�������롣

```python
class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        l=0
        r=n-1
        t=0
        b=n-1
        index=1
        matrix=[[0 for _ in range(n)]for _ in range(n)]
        while True:
            for i in range(l,r+1):
                matrix[t][i]=index
                index+=1
            t+=1
            if t>b:break

            for i in range(t,b+1):
                matrix[i][r]=index
                index+=1
            r-=1
            if l>r:break

            for i in range(r,l-1,-1):
                matrix[b][i]=index
                index+=1
            b-=1
            if t>b:break

            for i in range(b,t-1,-1):
                matrix[i][l]=index
                index+=1
            l+=1
            if l>r:break

        return matrix
```
