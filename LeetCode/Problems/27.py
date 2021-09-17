class Solution:
	def removeElement(self, nums: list[int], val: int) -> int:
		ret = []
		for i in nums:
			if i != val:
				ret.append(i)
		for i in range(len(ret)):
			nums[i] = ret[i]
		return len(ret)
