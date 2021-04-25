import csv
import os
from random import randint


MAXINT = 2147483647  # max integer value
MININT = -MAXINT


class Creator:
    @staticmethod
    def create_data():
        os.chdir("..")
        os.chdir("dataset")
        try:
            os.mkdir("data")
        except FileExistsError:
            pass
        os.chdir("data")
        try:
            os.mkdir("database")
        except FileExistsError:
            pass
        os.chdir("database")
        folders1 = ['insert']
        folders2 = ['01', '02', '03', '04', '05', '06', '07', '08', '09', '09', '10']
        amount = [100, 500, 1000, 5000, 10000, 50000, 100000, 500000, 1000000, 5000000]
        for a in folders1:
            try:
                os.mkdir(a)
            except FileExistsError:
                pass
            os.chdir(a)
            for b in folders2:
                try:
                    os.mkdir(b)
                except FileExistsError:
                    continue
                os.chdir(b)
                for i in amount:
                    file_name = f"Random_{i}.csv"
                    with open(file_name, "w", newline="") as file:
                        dataset = csv.writer(file)
                        for j in range(i):
                            dataset.writerow([randint(MININT, MAXINT)])
                os.chdir('..')
            os.chdir('..')

        print('Done')


if __name__ == "__main__":
    Creator.create_data()
