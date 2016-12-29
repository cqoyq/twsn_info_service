INCLUDE = -I$(BOOST_INCLUDE_ROOT) \
          -I$(BINGO_INCLUDE_ROOT_v3) \
          -I$(MYSQL_INCLUDE_ROOT) \
          -I./

ifeq ($(ConfigName),Debug)
LIBS = -lpthread \
	   -lrt \
	   -lbingo_v3_d \
	   -lboost_random \
	   -lboost_regex \
       -lboost_chrono \
	   -lboost_timer \
	   -lboost_system \
	   -lboost_thread \
	   -lboost_context \
	   -lboost_coroutine \
       -lboost_unit_test_framework
 else
 LIBS = -lpthread \
	   -lrt \
	   -lbingo_v3 \	   
	   -lboost_random \
	   -lboost_regex \
       -lboost_chrono \
	   -lboost_timer \
	   -lboost_system \
	   -lboost_thread \
	   -lboost_context \
	   -lboost_coroutine \
       -lboost_unit_test_framework
endif
	  
LIBPATH = -L$(BOOST_LIB_ROOT) \
		   -L$(MY_LIB_ROOT_v3) \
		   -L$(MYSQL_LIB_ROOT)

OBJS = main.o \
			local_logger.o \
			pb.o \
			rb.o \
			db.o \
			db_thr.o \
			rev_thr.o \
			Package/base.o \
			Package/package_factory.o \
			Package/unpack/message_0x6a_0x01.o \
			Package/unpack/message_0x6a_0x06.o \
			Package/unpack/message_0x6a_0x1c.o \
			Package/unpack/message_0x6a_0x1d.o \
			Package/unpack/message_0x6c_0x01.o \
			Package/unpack/message_0x6c_0x06.o \
			Package/unpack/message_0x6c_0x1c.o \
			Package/unpack/message_0x6c_0x0f.o \
			Handlers/base.o \
			Handlers/hdr_factory.o \
			Store/store_factory.o
		
ifeq ($(ShowDebug),y)
DEBUGS = -DMY_TEST
else
DEBUGS =
endif

ifeq ($(ConfigName),Debug)
CXXFLAGS =	-O0 -g -Wall -fmessage-length=0 -std=c++11 $(DEBUGS)  $(INCLUDE)
else
CXXFLAGS =	-O2 -Wall -fmessage-length=0  -std=c++11 $(INCLUDE)
endif

TARGET = twsn_info_service

$(TARGET):	$(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) $(LIBS) $(LIBPATH);
	cp $(TARGET) $(MY_LIB_ROOT_v3)/service/twsn_info_service

all: $(TARGET)

debug: $(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)


