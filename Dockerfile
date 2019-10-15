FROM alphine:3.9

RUN mkdir /app
WORKDIR /app

RUN npm install -g yarn 
COPY package.json yarn.lock /app/
RUN yarn

COPY . /app/

EXPOSE 8000
CMD ["yarn", "build"]