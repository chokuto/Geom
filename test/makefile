TARGET = test
OBJECTS = test.obj median_test.obj

CPPFLAGS = /nologo /W4 /EHsc /c /I../include
LINKFLAGS = /nologo /LTCG /subsystem:console /out:$(TARGET).exe
LIBS = gmock_main.lib gmock.lib

CC = @cl.exe
LK = @link.exe
RM = @del

all : $(TARGET).exe

$(TARGET).exe: $(OBJECTS)
	$(LK) $(LINKFLAGS) $(LIBS) $(OBJECTS)

.cpp.obj:
	$(CC) $(CPPFLAGS) $<

clean:
	$(RM) *.obj *.pdb $(TARGET).exe

rebuild: clean all
