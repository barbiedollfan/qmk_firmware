# sequence_transform setup
mkfile_dir := $(abspath $(dir $(lastword $(MAKEFILE_LIST))))

all: st_build

st_build:
	python3 $(mkfile_dir)/sequence_transform/generator/sequence_transform_data.py

include $(mkfile_dir)/sequence_transform/rules.mk
# end sequence_transform setup