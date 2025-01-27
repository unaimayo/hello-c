# use alpine as base image
FROM alpine:3.21.2 as build-env
# install build-base meta package inside build-env container
RUN apk add --no-cache build-base=0.5-r3
# change directory to /app
WORKDIR /app
# copy all files from current directory inside the build-env container
COPY . .
# Compile the source code and generate hello binary executable file
RUN gcc -o hello hello.c
# use another container to run the program
FROM alpine:3.21.2
# copy binary executable to new container
COPY --from=build-env /app/hello /app/hello
WORKDIR /app
# at last run the program
CMD ["/app/hello"] 
