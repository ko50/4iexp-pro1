#include "h/readData.h"

#include <stdio.h>
#include <stdlib.h>

#include "h/malloc2.h"

// Please free() returned data, end of program
Data *readData(FILE *fp) {
    unsigned num;
    fscanf(fp, "%d", &num);

    Datum *datumList = (Datum *)malloc2(sizeof(Datum) * num);
    Data *data = (Data *)malloc2(sizeof(Data));

    double x, y;
    for (int i = 0; i < num; i++) {
        fscanf(fp, "%lf", &x);
        fscanf(fp, "%lf", &y);

        Datum datum = {x, y};
        datumList[i] = datum;
    }

    data->num = num;
    data->data = datumList;

    return data;
}
