FROM rust:latest
# Set the working directory
WORKDIR /app
# Copy all files from the current directory to the container
COPY . .
# Build the project
RUN cargo build --release
# Copy the binary to the /usr/local/bin directory
RUN cp target/release/tfetch /usr/local/bin/
# Run the binary
CMD ["tfetch"]