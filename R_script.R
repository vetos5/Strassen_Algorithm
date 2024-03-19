library(ggplot2)

data <- read.csv("E:/gitrepos/uni_proj_library/Strassen_Algorithm/input_value.csv")  # Adjust file path as needed

str(data);

plot1 <- ggplot(data, aes(x = input_size)) +
  geom_line(aes(y = standart_t, color = "Standart")) +
  geom_point(aes(y = standart_t, color = "Standart")) +
  geom_line(aes(y = strassen_t, color = "Strassen")) +
  geom_point(aes(y = strassen_t, color = "Strassen")) +
  labs(x = "Input Size", y = "Time, ms", color = "Algorithm") +
  ggtitle("Standard algorithm vs. Strassen algorithm execution time") +
  theme_minimal() +
  scale_color_manual(values = c("Standart" = "blue", "Strassen" = "red"))

print(plot1)

# Plot for Time Value 2
plot2 <- ggplot(data, aes(x = input_size, y = strassen_execution_time)) +
  geom_line(color = "red") +
  geom_point(color = "red") +
  labs(x = "Input Size", y = "Time, ms") +
  ggtitle("Strassen algorithm execution time") +
  theme_minimal()

# Display plots
print(plot2)