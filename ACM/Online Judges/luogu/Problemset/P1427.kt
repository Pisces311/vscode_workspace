fun main() {
    var a = readLine()!!.split(' ').map(String::toInt)
    a = a.reversed()
    for (i in a) {
        if (i == 0) continue
        else print("$i ")
    }
}