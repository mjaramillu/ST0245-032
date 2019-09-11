//Complejidad: O(n)
public int countEvens (int[] nums) {
  int count = 0;#C1
  for (int i = 0; i<nums.length; i++){ //C1+n+1+n = 2n
    if (nums[i]%2==0) count++;//C2*2n
  }
  return count; //T(n) = C1+C2*2n=2n=n
}
//Complejidad: O(n)
public int centeredAverage (int[] nums) {
  int smallerNum = nums[1];//C1
  int biggestNum = nums[1];//C2
  int sum = 0;//C3
  for(int i = 0; i<nums.length;i++)//C1+n+1+n=2n
  {
    if(nums[i] < smallerNum){//C4
      smallerNum=nums[i];
    }
    if(nums[i] > biggestNum)//C5
    {
      biggestNum=nums[i];
    }
    sum+=nums[i];
  }
  int average = (sum-(smallerNum+biggestNum))/(nums.length-2);//C6
  return average; //T(n)= C1+C2+2n*C3 = 2n
}
//Complejidad: O(n)
public int sum13(int[] nums) {
  int sum = 0;
  for(int i = 0; i<nums.length; i++)
  if(nums[i]==13)
  {
    i++;
  }
  else
  {
    sum+=nums[i];
  }
  return sum;
}
//Complejidad: O(n)
public boolean has22(int[] nums) {
  boolean isTwo = false;
  boolean isTwentyTwo = false;
  for(int i = 0; i<nums.length; i++)
  {
    if(nums[i]==2 && isTwo)
    {
      return true;
    }
    if(nums[i]==2)
    {
      isTwo = true;
    }
    else
    {
      isTwo=false;
    }

  }
  return false;
}
//Complejidad: O(n)
public int[] fizzArray(int n) {
 int[] nums = new int[n];
  for(int i= 0; i<nums.length; i++)
  {
    nums[i]=i;
  }
  return nums;
}
