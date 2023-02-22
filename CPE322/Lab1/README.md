# Lab 1: GHDL and GTKWave

## Part 1: Downloading GHDL and GTKWave

This part of the lab involves downloading and installing GHDL and GTKWave. GHDL is a simulator for VHDL, and GTKWave is a waveform viewer. Both are free and open source.

### GHDL

GDHL was downloaded and then added to my system PATH using the following commands:

```bash
$ cd Downloads
$ sudo mv ghdl-0.37-macosx-mcode /usr/local
$ vim /etc/paths
```

Then I added the following line to the end of the file:

```bash
/usr/local/ghdl-macos-12-mcode/bin
```

This allows me to run GHDL from any directory.

### GTKWave

GTKWave was downloaded and added to the applications folder.
