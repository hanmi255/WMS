FROM openjdk:8
MAINTAINER 01star
ADD target/wms-j2-sysmgr-1.0.0-SNAPSHOT.jar app.jar
ENV JAVA_OPTS="-Xms512m -Xmx512m"
ENV SPRING_ARGS=""
RUN echo "JAVA_OPTS=" $JAVA_OPTS
CMD java $JAVA_OPTS -jar app.jar --logging.file.path=/tmp/logs/spring-boot $SPRING_ARGS






