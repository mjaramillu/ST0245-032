#Complejidad O(n^2)
public int maxSpan(int[] nums) {
  int Span = 0;
  for(int i = 0; i<nums.length; i++)
  {
    for(int j = nums.length-1; j>=0;j--)
    {
      if(nums[j] == nums[i])
      {
        int possibleSpan = j-i+1;
        Span = Math.max(Span, possibleSpan);
      }
    }
  }
  return Span;
}
#Complejidad: O(n^2)
public int[] fix34(int[] nums) {
  int lastIndex4 = 0;
  for(int i = 0; i<nums.length; i++)
  {
    if(nums[i] == 3)
    {
      for(int j = lastIndex4+1; j<nums.length; j++)
      {
        if(nums[j]==4)
        {
          lastIndex4 = j;
          break;
        }
      }
      int replace = nums[i+1];
      nums[i+1]=4;
      nums[lastIndex4] = replace;
    }
  }
  return nums;
}
#Complejidad: O(n^2)
public int[] fix45(int[] nums) {
  for(int i = 0; i<nums.length; i++)
  {
    if (nums[i]==4)
    {
      for(int j = 0; j<nums.length; j++)
      {
        if(nums[j]==5)
        {
          if (j>0 && nums[j-1] != 4)
          {
            int replace = nums[i+1];
            nums[i+1] = nums[j];
            nums[j] = replace;
          }
          else if (j==0)
          {
            int replace = nums[i+1];
            nums[i+1] = nums[j];
            nums[j] = replace;
          }
        }
      }
    }
  }
  return nums;
}
#Complejidad: O(n^2)
public boolean linearIn(int[] outer, int[] inner) {

  for(int i = 0; i<inner.length;i++)
  {
    boolean isIn = false;
    int num = inner[i];
    for(int j = 0; j<outer.length;j++)
    {
      if(num==outer[j])
      {
        isIn = true;
      }
      else if (!isIn && j==outer.length-1)
      {
        return false;
      }
    }
  }
  return true;
}
#Complejidad: O(n^2)
public int maxMirror(int[] nums) {
  int max = 0;
  for(int i = 0; i < nums.length; i++)
  {
    int count = 0;
    for(int j = nums.length-1; i+count<nums.length && j>= 0; j--)
    {
      if (nums[i+count]==nums[j])
      {
        count++;
      }
      else if(count > 0)
      {
        max = Math.max(count, max);
        count = 0;
      }
    }
    max = Math.max(count, max);
  }
  return max;
}
