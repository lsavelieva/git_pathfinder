void mx_print_invalid_line(int number) {
    mx_printerr("error: line [");
    mx_printerr(mx_itoa(number));
    mx_printerr("] is not valid\n");
}
