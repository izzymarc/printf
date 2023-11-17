/*
 * preciseCalcModule - Calculates the precision for printing.
 *
 * This function calculates the precision for printing based on the provided
 * format, index, and variable argument list.
 *
 * @format: Formatted string in which to print the arguments.
 * @i: Index of the argument in the format string.
 * @list: Variable argument list.
 *
 * Return: Precision value.
 */
int preciseCalcModule(const char *format, int *i, va_list list)
{
    int curr_i = *i + 1;
    int precision = -1;

    if (format[curr_i] != '.')
        return (precision);

    precision = 0;

    for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
    {
        if (is_digit(format[curr_i]))
        {
            precision *= 10;
            precision += format[curr_i] - '0';
        }
        else if (format[curr_i] == '*')
        {
            precision = va_arg(list, int);
            break;
        }
        else
            break;
    }

    /* Check if precision is negative, if yes, treat it as 0 */
    precision = (precision < 0) ? 0 : precision;

    *i = curr_i - 1;

    return (precision);
}
