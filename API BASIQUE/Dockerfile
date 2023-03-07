FROM node AS build
WORKDIR /app
COPY package*.json /app/
RUN ["npm","install"]
COPY . /app/
RUN ["npx","tsc"]

FROM alpine:3
RUN apk add nodejs --no-cache 
ENV PING_LISTEN_PORT=3000
EXPOSE 3000
RUN ["adduser","--disabled-password","Razmo"]

WORKDIR /app
COPY --from=build /app/node_modules /app/node_modules
COPY --from=build /app/build /app/build
USER Razmo
CMD ["node","build/index.js"]