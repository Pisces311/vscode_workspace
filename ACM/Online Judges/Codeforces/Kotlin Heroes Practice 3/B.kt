fun main() {
    var n = readLine()!!.toInt()
    var a = readLine()!!.split(' ').map(String::toInt).reversed().toSet().reversed()
    println(a.size)
    println(a.joinToString(" "))
}