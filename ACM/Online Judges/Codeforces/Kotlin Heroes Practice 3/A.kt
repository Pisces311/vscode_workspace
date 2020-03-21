fun main() {
    var nums = readLine()!!.split(' ').map(String::toInt).sorted()
    var a = (nums[0] + nums[1] - nums[2]) / 2
    var b = (nums[1] + nums[2] - nums[0]) / 2
    var c = nums[3] - a - b
    println("$a $b $c")
}