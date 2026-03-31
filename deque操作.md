# 初始化

```
deque<int> dq;
```

# 加入元素

```
dq.push_back(nums[i]);   // 从尾部加入
dq.push_front(nums[i]);  // 从头部加入
```

# 删除元素

```
dq.pop_front();  // 删除头部
dq.pop_back();   // 删除尾部
```

# 查看元素

```
dq.front();  // 查看头部（最大值）
dq.back();   // 查看尾部（最小值）
```

# 判断为空

```
dq.empty()
```

# 单调递减维护（滑动窗口最大值）

```
// 新元素入队前，弹出所有比它小的（用>不用>=，保留重复值）
while(!dq.empty() && nums[i] > dq.back())
    dq.pop_back();
dq.push_back(nums[i]);

// 窗口滑动时，删除过期的头部
if(j >= 0 && dq.front() == nums[j]) dq.pop_front();
```
