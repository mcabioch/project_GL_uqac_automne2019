DOCKER = sudo docker

USER = mcabioch
PROJECT = $(shell basename $(CURDIR))

TAGNAME = $(shell $(DOCKER) images | grep $(PROJECT) | grep -v $(USER) | tr -s ' ' | cut -d' ' -f 1-2 | sed "s| |:|g")
ONLINE_TAG = $(USER)/$(TAGNAME)

.PHONY: create build push

create:
	

build:
	$(DOCKER) build -t $(PROJECT) .

push: build
	$(DOCKER) tag $(TAGNAME) $(ONLINE_TAG)
	$(DOCKER) push $(ONLINE_TAG)

