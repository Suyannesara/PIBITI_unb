.PHONY: all build go

# O alvo padrão é "all", que chama "build"
all: build

# Alvo de build que cria a pasta "build", roda cmake e make
build:
	mkdir -p build
	cd build && cmake ..
	cd build && make

# Alvo que executa o binário InterestPoint
go:
	./build/InterestPointProcessing
