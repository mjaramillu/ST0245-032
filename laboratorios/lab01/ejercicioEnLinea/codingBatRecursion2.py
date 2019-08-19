#Complejidad: O(2^n)
public boolean groupSum6(int start, int[] nums, int target) {
  if (start >= nums.length) return target==0;#C1
  if (groupSum6(start+1, nums, target-nums[start])) return true;;#T(n-1)
  if (nums[start]!=6 && groupSum6(start+1, nums, target))return true;#T(n-1)
return false;
}

#Complejidad: O(2^n)
public boolean groupNoAdj(int start, int[] nums, int target) {
  if (start >= nums.length)return target==0;
  if(groupNoAdj(start+2, nums, target-nums[start]))return true;
  if(groupNoAdj(start+1, nums, target))return true;
else return false;
}

#Complejidad: O(2^n)
public boolean groupSum5(int start, int[] nums, int target) {
  if(start >= nums.length)return target ==0;
  if (groupSum5(start+1, nums, target-nums[start])&&skipOne(start, nums))return true;
  if (nums[start]%5!=0 && groupSum5(start+1, nums, target))return true;
else return false;
}
private boolean skipOne(int start, int[] nums){
    if (start==0)return true;
    if (start>0 && nums[start-1]%5==0 && nums[start]==1) return false;
    else return true;
}

#Complejidad: O(2^n)
public boolean groupSumClump(int start, int[] nums, int target) {
  noRepeatNums(nums);
  if(start>=nums.length)return target==0;
  if(groupSumClump(start+1, nums, target-nums[start]))return true;
  if(groupSumClump(start+1, nums, target))return true;
else return false;
}
private void noRepeatNums(int[] nums){
  for(int i = 0; i < nums.length; i++){
    if(i>0 && nums[i]==nums[i-1]){
      nums[i-1]+=nums[i];
      if((i+1<nums.length && nums[i]!=nums[i+1])||(i==nums.length-1)) nums[i]=0;
    }
  }
}
#Complejidad: O(2^n)
public boolean splitArray(int[] nums) {
  int sum1 = 0;
  int sum2 = 0;
  int start =0;
  return sumArray(start, nums, sum1, sum2);#C1
}
private boolean sumArray(int start, int[] nums, int sum1, int sum2){
  if(start>=nums.length)return sum1==sum2;#C2
  else if(sumArray(start+1, nums, sum1+nums[start], sum2)||sumArray(start+1, nums, sum1, sum2+nums[start])) return true;#T(n)=T(n-1)+T(n-1)+C1
else return false;
}
