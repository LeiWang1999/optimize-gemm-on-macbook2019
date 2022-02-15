import glob
import matplotlib.pyplot as plt
import numpy as np


class PlotFile(object):
    def __init__(self, fileName):
        self._title, self._sizes, self._times = self._solveFile(fileName)

    def getTitle(self):
        return self._title

    def getSizes(self):
        return self._sizes

    def getTimes(self):
        return self._times

    def _solveFile(self, filename):
        f = open(filename)
        sizes = [40]
        times = [0.0]
        title = filename.split('.')[0]
        while True:
            line = f.readline()
            if line:
                slices = line.split(" ")
                if len(slices) <= 2:
                    break
                size = int(slices[0])
                time = float(slices[1])
                sizes.append(size)
                times.append(time)
            else:
                break
        return title, sizes, times


class BenchMark(object):
    '''
        eat a path and get a
    '''

    def __init__(self, path='*.txt'):
        _fileList = glob.glob(path)
        self._plotFileList = []

        for filename in _fileList:
            self._plotFileList.append(PlotFile(filename))

    def plotAll(self):
        plt.xlabel('size')
        plt.ylabel('gflops')

        for _plotFile in self._plotFileList:
            plt.plot(_plotFile.getSizes(), _plotFile.getTimes(), label=_plotFile.getTitle())

        plt.legend()
        plt.savefig('benmark.png')
        plt.show()

if __name__ == '__main__':
    benchMark = BenchMark()
    benchMark.plotAll()